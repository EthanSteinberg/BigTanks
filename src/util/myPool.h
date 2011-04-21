#ifndef MY_POOL_H_INCLUDED
#define MY_POOL_H_INCLUDED

#include <boost/utility.hpp>
#include <boost/function.hpp>

#include <pthread.h>

class t_myPool : boost::noncopyable
{
public:
   t_myPool(int num = 10);
   ~t_myPool();
   void addTask(const boost::function<void(void)> &func);

   struct threadData
   {
      int fd;
      pthread_mutex_t *mutex;
   };

   
private:
   pthread_mutex_t mutex;
   std::vector<pthread_t> threads;
   int fds[2];

};


#endif
