#include "tanksMid.h"

bool t_tanksMid::processMessage(const t_message &mess)
{
   switch (mess.id)
   {
   case t_message::string:
   {
      printf("Mid has recieved a string\n");
      const char *text = static_cast<const char *>(mess.data);
      printf("%s\n",text);
      break;
   }

   case t_message::closed:
   {
      printf("Mid has lost the connection\n");
      return false;
   }
   break;

   default:
      printf("The mid does not know what it recieved\n");
   }

   return true;
}
