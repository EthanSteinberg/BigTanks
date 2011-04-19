#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include <cstddef>

struct t_message
{
public:
   enum type
   {
      none = 0,
      closed,
      string
   };

   type id;
   void *data;

   t_message(type ident = none, void * dat = NULL);

private:

};


#endif
