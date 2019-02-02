#include "cotton.h"

namespace cotton{
    void push_task_to_runtime(void *ptr,int index);
    void *worker_routine(void *ptr);
    void *grab_task_from_runtime();
    void lock_deq(int index);
    void unlock_deq(int index);
    void lock_finish();
    void unlock_finish();
    void find_and_execute_task();
    void execute_task(void (*task)(void));
    int thread_pool_size();

}
