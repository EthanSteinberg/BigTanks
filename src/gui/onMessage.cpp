#include "tanksGui.h"
#include <string>

bool t_tanksGui::onMessage(const t_message &mess)
{
   switch (mess.id)
   {
   case t_message::string:
   {
      printf("I have recieved a string\n");
      std::string *text  = static_cast<std::string *>(mess.data);
      printf("%s\n",text->c_str());
      delete text;
      break;
   }

   case t_message::gameOpened:
   {
      printf("I have recieved confirmation of a game opening\n");

      graphicsWindow->show();
      gameWindow->start();

      break;
   }


   default:
      printf("I have no idea what I recieved\n");
   }

   return true;
}
