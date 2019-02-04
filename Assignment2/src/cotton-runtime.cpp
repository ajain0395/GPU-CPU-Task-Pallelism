#include "cotton-runtime.h"
#include <cstring>
#include <iostream>
#include <pthread.h>
#include <stdlib.h>

#define DEQ_SIZE 500

namespace cotton{

    typedef struct _thread_key_data_
    {
        int index;
    }thread_data_t;

    typedef struct _thread_deq_
    {
        int front;
        void **deq;
        int rear;
    }thread_deq_t;


    /*
       init_runtime();
       start_finish();
       async (S1);
       S2;
       end_finish();
       finalize_runtime();
     */

    pthread_t *threads; //number of threads
    pthread_mutex_t mutexfinish,*mutexlocks; //locks for each task pool bucket
    thread_data_t *deqindex ; // index of each thread for worker routine key deq mapping
    thread_deq_t *threads_queues ;//threads deques
    pthread_key_t key;//keys for for all thread specific index fetching
    static pthread_once_t key_once = PTHREAD_ONCE_INIT;
    volatile int finish_counter = 0;//counter for task remaining in queues
    volatile bool shutdown = false; // flag for worker routines polling enable/disable

    static void make_key()
    {
        (void) pthread_key_create(&key, NULL);
    }
    void insert_into_deq(int index, void *value)
    {
        lock_deq(index);
            if ((threads_queues[index].front == 0 && threads_queues[index].front == DEQ_SIZE-1) || (threads_queues[index].rear == (threads_queues[index].front-1)%(DEQ_SIZE-1))) 
            { 
                printf("\nQueue is Full"); 
                return; 
            } 

            else if (threads_queues[index].front == -1) /* Insert First Element */
            { 
                threads_queues[index].front = threads_queues[index].rear = 0; 
                threads_queues[index].deq[threads_queues[index].rear] = value; 
            } 

            else if (threads_queues[index].rear == DEQ_SIZE-1 && threads_queues[index].front != 0) 
            { 
                threads_queues[index].rear = 0; 
                threads_queues[index].deq[threads_queues[index].rear] = value;
            } 

            else
            { 
                threads_queues[index].rear++; 
                threads_queues[index].deq[threads_queues[index].rear] = value; 
            } 

        unlock_deq(index);
    }
    void *steal_from_deq(int index)
    {
        /////////////////////
        lock_deq(index);
   if (threads_queues[index].front == -1) 
    { 
        printf("\nQueue is Empty");
        unlock_deq(index);
        return NULL; 
    } 
  
    void *data = threads_queues[index].deq[threads_queues[index].front]; 
    threads_queues[index].deq[threads_queues[index].front] = NULL; 
    if (threads_queues[index].front == threads_queues[index].rear) 
    { 
        threads_queues[index].front = -1; 
        threads_queues[index].rear = -1; 
    } 
    else if (threads_queues[index].front == DEQ_SIZE-1) 
        threads_queues[index].front = 0; 
    else
        threads_queues[index].front++; 
  
    unlock_deq(index);
    return data; 
        ////////////////////

    }
    void *pop_from_deq(int index)
    {
        /////////////////////
        lock_deq(index);
   if (threads_queues[index].front == -1)
    { 
        printf("\nQueue is Empty");
        unlock_deq(index);
        return NULL; 
    } 
  
    void *data = threads_queues[index].deq[threads_queues[index].rear]; 
    threads_queues[index].deq[threads_queues[index].rear] = NULL; 
    if (threads_queues[index].front == threads_queues[index].rear)
    { 
        threads_queues[index].front = -1;
        threads_queues[index].rear = -1; 
    } 
    else if (threads_queues[index].rear == 0) 
        threads_queues[index].rear = DEQ_SIZE - 1; 
    else
        threads_queues[index].rear--;
  
    unlock_deq(index);
    return data; 
        ////////////////////

    }
    void init_runtime()
    {
        int size = thread_pool_size();
        threads = new pthread_t[size - 1];
        mutexlocks = new pthread_mutex_t[size];
        deqindex = new thread_data_t[size];
        threads_queues = new thread_deq_t[size]; // allocating memory to queues for threads including main thread

        (void) pthread_once(&key_once, make_key);
        
        for(int i = 0; i<size ;i++)
        {
            pthread_mutex_init(&mutexlocks[i], NULL);
            deqindex[i].index = i;
            threads_queues[i].deq = (void**)malloc(sizeof(void*) * DEQ_SIZE);
            threads_queues[i].front = -1;
            threads_queues[i].rear = -1;
        }
        for(int i = 0; i<size - 1 ;i++)
        {
            pthread_create(&threads[i],
                    NULL,
                    worker_routine,
                    &deqindex[i]
                    );
            //create thread and pass it to worker routine
        }
        if (pthread_getspecific(key) == NULL)
        {
        int *val = (int*)malloc(sizeof(int));
        *val = size -1;
        (void) pthread_setspecific(key, val);
        }
    }
    void start_finish()
    {
        finish_counter=0;//reset
    }
    void async(std::function<void()> &&lambda) //accepts a C++11 lambda function
    {
        int *getvalue = (int*)pthread_getspecific(key);
        int index = *getvalue;
        lock_finish();
        finish_counter++;//concurrent access
        unlock_finish();
        //task size retrieval
        int task_size = sizeof(lambda);
        //copy	task	on	heap
        void *p =(void*)malloc(task_size);
        memcpy(p,&lambda,task_size);
        //thread-safe	push_task_to_runtime
        //index of shelf
        push_task_to_runtime(p,index);
        return;
    }
    void push_task_to_runtime(void *ptr,int index)
    {
        //push task
        insert_into_deq(index, ptr);
    }
    void end_finish()
    {
        while(finish_counter !=	0)
        {
            find_and_execute_task();
        }
    }

    void *worker_routine(void *indexdata)
    {
        //thread_deq_t deque ;
        //thread_deq_t *thread_deq ;//thread specific deque
        //thread_key_data_t *data = (thread_key_data_t *)indexdata;

        thread_data_t *data = (thread_data_t*)indexdata;
        if (pthread_getspecific(key) == NULL) 
        {
            int *val;
            val = (int*)malloc(sizeof(int));
            *val = data->index;
            (void) pthread_setspecific(key, val);
        }
        while(!shutdown)
        {
            find_and_execute_task();
        }
    }
    bool isempty(int indexi)
    {
        if(threads_queues[indexi].front == -1)
        {
            return true;
        }
        return false;
    }
    void *grab_task_from_runtime() //grab task from thread deque or steal from victims deque
    {
        int *getvalue = (int*)pthread_getspecific(key);
        if(getvalue != NULL)
        {
            int indexi = *getvalue;
            if(!isempty(indexi))
            {
                return pop_from_deq(indexi);
            }
            else 
            {
                int randomindex;
                do
                {
                    randomindex = rand() % thread_pool_size();
                }while(randomindex == indexi);
                if(!isempty(randomindex))
                {
                    return steal_from_deq(randomindex);
                }
                return NULL;
            }
        }
        return NULL;
    }
    void lock_deq(int index)
    {
        pthread_mutex_lock(&mutexlocks[index]);
    }
    void unlock_deq(int index)
    {
        pthread_mutex_unlock(&mutexlocks[index]);
    }
    //lock aquire
    void lock_finish()
    {
        pthread_mutex_lock(&mutexfinish);
    }
    //unlock
    void unlock_finish()
    {
        pthread_mutex_unlock(&mutexfinish);
    }
    void find_and_execute_task()
    {
        //grab_from_runtime	is	thread-safe
        void *task;
        task=grab_task_from_runtime();
        if(task	!=	NULL)
        {
            execute_task(task);
            free(task);
            lock_finish();
            finish_counter--;
            unlock_finish();
        }
    }
    typedef void sigrout_t();
    void execute_task(void *task)
    {
        (*(std::function<void()> *)task) ();
        
     //   *((sigrout_t*) task) ();
        //  task();
    }
    int thread_pool_size()
    {
        int envsize =atoi(std::getenv("COTTON_WORKERS"));
       return (envsize>1)?envsize:1;
    }
    void finalize_runtime()
    {
        //all	spinning	workers
        //will	exit	worker_routine
        shutdown=true;
        int	size=thread_pool_size();
        //	master	waits	for	helpers	to	join
        for(int i= 0 ;	i<size - 1;	i++)
        {
            pthread_join(threads[i],NULL);
        }
    }
}
