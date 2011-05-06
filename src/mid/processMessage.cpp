#include "tanksMid.h"
#include <string>

bool t_tanksMid::processMessage(const t_message &mess)
{
   switch (mess.id)
   {
   case t_message::string:
   {
      printf("Mid has recieved a string\n");
      std::string *text = static_cast<std::string *>(mess.data);
      printf("%s\n",text->c_str());
      delete text;
      break;
   }

   case t_message::closed:
   {
      printf("Mid has lost the connection\n");
      return false;
   }
   break;

   case t_message::gameOpened:
   {
      printf("The game has been opened\n");
      sharedData.guiQueue.push(mess);
      break;
   }

   default:
      printf("The mid does not know what it recieved\n");
   }

   return true;
}
