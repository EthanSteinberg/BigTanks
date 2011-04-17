#include "message.h"

#include <cstring>

#include <type_traits>
#include <cstdio>

t_message::t_message(const std::string &object ,char ident)
   {
      id = ident;

      data = new char[object.size() + 1];
      strcpy(data,object.c_str());
   }

t_message::t_message(char ident)
{
   id = ident;
   data = NULL;
}

t_message::~t_message()
{
   delete [] data;
}
