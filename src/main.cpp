#include <cstdio>
#include <iostream>
#include <gtkmm.h>

#include <unistd.h>

#include <boost/bind.hpp>
#include <boost/function.hpp>

#include "shared.h"

#include "mid/tanksMid.h"
#include "gui/tanksGui.h"

void *startMid(void *ptr)
{
   try
   {
      t_sharedData *sharedData = reinterpret_cast<t_sharedData *>(ptr);

      t_tanksMid mid(*sharedData);

      sharedData->guiQueue.closeRead();
      sharedData->guiQueue.closeWrite();
      sharedData->midQueue.closeRead();
      sharedData->midQueue.closeWrite();

      mid.run();
   }

   catch (std::exception &e)
   {
      std::cout<<e.what()<<std::endl;
   }

   return NULL;
}

int main(int argv, char **argc)
{

   try
   {
      Gtk::Main main(argv,argc);

      pthread_t midThread;

      t_sharedData sharedData;

      {
         t_tanksGui gui(sharedData);


         if (pthread_create(&midThread,NULL,startMid,&sharedData))
         {
            perror("pthread_create problem");
            exit(-1);
         }


         gui.run();
      }

      if (pthread_join(midThread,NULL))
      {
         perror("pthread_join problem");
         exit(-2);
      }
   }

   catch (std::exception &e)
   {
      std::cout<<e.what()<<std::endl;
   }

   printf("Hello world\n");
   return 0;
}
