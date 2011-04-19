#include "message.h"

t_message::t_message(t_message::type ident, const void * dat)
{
   id = ident;
   data = dat;
}
