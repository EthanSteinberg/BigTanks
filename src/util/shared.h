#ifndef SHARED_H_INCLUDED
#define SHARED_H_INCLUDED

#include "myQueue.h"

struct t_sharedData
{
   t_myQueue guiQueue;
   t_myQueue midQueue;
};


#endif
