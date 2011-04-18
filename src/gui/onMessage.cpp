#include "tanksGui.h"

bool t_tanksGui::onMessage(const t_message &mess)
{
   switch (mess.id)
   {
   case t_message::string:
      printf("I have recieved a string\n");
      printf("%s\n",mess.data);
      break;

   default:
      printf("I have no idea what I recieved\n");
   }

   return true;
}
