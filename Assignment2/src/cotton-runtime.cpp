#include "cotton-runtime.h"
#include<cstring>
#include <iostream>
#include <pthread.h>
namespace cotton{

    typedef struct _thread_key_data_
    {
        int index;
    }thread_key_data_t;


    /*
       init_runtime();
       start_finish();
       async (S1);
       S2;
       end_finish();
       finalize_runtime();
     */

    pthread_t *threads;
    pthread_mutex_t *mutex;
    thread_key_data_t *keysindex ;
    pthread_key_t *keys;
    volatile int finish_counter = 0;
    volatile bool shutdown = false;

    void init_runtime()
    {
        int size = thread_pool_size();
        threads = new pthread_t[size - 1];
        keysindex = new thread_key_data_t[size - 1];
        keys = new pthread_key_t[size - 1];
        pthread_mutex_t *mutexlocks = new pthread_mutex_t[size - 1];

        for(int i = 0; i<size - 1 ;i++)
        {
            keysindex[i].index = i;
        pthread_mutex_init(&mutexlocks[i], NULL);
            int status =  pthread_create(&threads[i],
                    NULL,
                    worker_routine,
                    &keysindex[i]
                    );
            //create thread and pass it to worker routine
        }
    }
    void start_finish()
    {
        finish_counter=0;//reset
    }
    void async(std::function<void()> &&lambda) //accepts a C++11 lambda function
    {
        lock_finish(0);
        finish_counter++;//concurrentaccess
        unlock_finish(0);
        //task size retrieval
        int task_size = 0;
        void *task;
        //copy	task	on	heap
        void*	p=malloc(task_size);
        memcpy(p,task,task_size);
        //thread-safe	push_task_to_runtime
        int index = 0;
        //index of shelf
        push_task_to_runtime(&p,index);
        return;
    }
    void push_task_to_runtime(void *ptr,int index)
    {
        //push task
    }
    void end_finish()
    {
        while(finish_counter !=	0)
        {
            find_and_execute_task();
        }
    }
    void *worker_routine(void *ptr)
    {
        thread_key_data_t *data = (thread_key_data_t *)ptr;

        pthread_key_create(&keys[data->index],NULL);
        while(!shutdown)
        {
            find_and_execute_task();
        }
    }
    void *grab_task_from_runtime()
    {

    }
    //lock aquire
    void lock_finish(int index)
    {

        pthread_mutex_lock(&mutex[index]);

    }
    //unlock
    void unlock_finish(int index)
    {
        pthread_mutex_unlock(&mutex[index]);
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
            lock_finish(0);
            finish_counter--;
            unlock_finish(0);
        }
    }
    void execute_task(std::function<void(int,int)> task )
    {
        task(1,2);
    }
    int thread_pool_size()
    {
       return atoi(std::getenv("COTTON_WORKERS"))>1?atoi(std::getenv("COTTON_WORKERS")):1;
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
