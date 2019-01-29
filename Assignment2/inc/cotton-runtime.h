#include "cotton.h"

namespace cotton{
    void push_task_to_runtime(void *ptr,int index);
    void *worker_routine(void *ptr);
    void *grab_task_from_runtime();
    void lock_finish(int index);
    void unlock_finish(int index);
    void find_and_execute_task();
    void execute_task(std::function<void(int,int)> task);
    int thread_pool_size();

}
