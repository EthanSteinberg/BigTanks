#include "myPool.h"

#include <unistd.h>
#include <syscall.h>
#include <pthread.h>

static void *createThread(void *data)
{
   t_myPool::data *stuff = static_cast<t_myPool::data *>(data);


   boost::function<void(void)> *func;

   *(stuff->ready) = true;

   while (read(stuff->fd,&func,sizeof(func)) !=0)
   {
      (*func)();

      delete func;
      *(stuff->ready) = true;
   }

   printf("eof for me tid = %ld\n", syscall(SYS_gettid));

   close(stuff->fd);
   delete stuff->ready;
   delete stuff;

   return NULL;
}

t_myPool::t_myPool(int num) : threads(num)
{
   pos = 0;

   for (unsigned int i = 0 ; i < threads.size(); i++)
   {
      int fds[2];
      pipe(fds);

      threads[i].ready = new bool(false);
      threads[i].fd = fds[1];

      data *threadData = new data;
      threadData->ready = threads[i].ready;
      threadData->fd = fds[0];

      pthread_create(&(threads[i].thread),NULL, createThread,threadData);
   }
}


void t_myPool::addTask(const boost::function<void(void)> &func)
{
   int oldPos = pos + threads.size();

   while (*(threads[pos%threads.size()].ready) == false && pos != oldPos)
   {
      pos++;
   }

   if (pos == oldPos)
   {
 //     printf("All the threads are taken\n");
   }

   *(threads[pos%threads.size()].ready) = false;
   boost::function<void(void)> *funcPtr = new boost::function<void(void)>(func);
   write(threads[pos%threads.size()].fd,&funcPtr,sizeof(funcPtr));
   pos++;
}

t_myPool::~t_myPool()
{
   for (int i = 0; i< threads.size();i++)
   {
      close(threads[i].fd);
      pthread_join(threads[i].thread,NULL);
   }
}
