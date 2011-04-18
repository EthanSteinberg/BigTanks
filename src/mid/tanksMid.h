#ifndef TANKS_MID_H_INCLUDED
#define TANKS_MID_H_INCLUDED

#include <boost/utility.hpp>


#include "shared.h"

class t_tanksMid : boost::noncopyable
{
public:
   t_tanksMid(t_sharedData theSharedData);
   ~t_tanksMid();

   void run();

private:
   bool processMessage(const t_message &message);

   t_sharedData sharedData;

};


#endif
