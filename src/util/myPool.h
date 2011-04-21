#ifndef MY_POOL_H_INCLUDED
#define MY_POOL_H_INCLUDED

#include <boost/utility.hpp>
#include <boost/function.hpp>

class t_myPool : boost::noncopyable
{
public:
   t_myPool(int num = 10);
   ~t_myPool();
   void addTask(const boost::function<void(void)> &func);

   struct data
   {
      int fd;
      bool *ready;
      pthread_t thread;
   };

   
private:
   std::vector<data> threads;
   int pos;

};


#endif
