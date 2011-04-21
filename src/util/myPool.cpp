#include "myPool.h"

#include <unistd.h>
#include <syscall.h>

static void *createThread(void *data)
{
   t_myPool::threadData *stuff = static_cast<t_myPool::threadData *>(data);

   boost::function<void(void)> *func;

   for (;;)
   {
      pthread_mutex_lock(stuff->mutex);
      int status = read(stuff->fd,&func,sizeof(func));
      pthread_mutex_unlock(stuff->mutex);

      if (status == 0)
         break;
      
      (*func)();
      delete func;
   }

   printf("eof for me tid = %ld\n", syscall(SYS_gettid));

   delete stuff;

   return NULL;
}

t_myPool::t_myPool(int num) : threads(num)
{
   
   pthread_mutex_init(&mutex,NULL);

   pipe(fds);

   for (unsigned int i = 0 ; i < threads.size(); i++)
   {
      threadData *data = new threadData;
      data->fd = fds[0];
      data->mutex = &mutex;

      pthread_create(&(threads[i]),NULL, createThread,data);
   }
}


void t_myPool::addTask(const boost::function<void(void)> &func)
{
   boost::function<void(void)> *funcPtr = new boost::function<void(void)>(func);
   write(fds[1],&funcPtr,sizeof(funcPtr));
}

t_myPool::~t_myPool()
{
   close(fds[1]);
   
   for (unsigned int i = 0; i< threads.size();i++)
   {
      pthread_join(threads[i],NULL);
   }

   close(fds[0]);
   pthread_mutex_destroy(&mutex);
}
