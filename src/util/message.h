#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include <string>
#include <cstring>

struct t_message
{
public:
   enum 
   {
      none = 0,
      string
   };

   unsigned char id;
   char *data;

   template <class myType>
   t_message(const myType &object, char ident)
   {
      printf("Creating it\n");
      createIt(object,ident,std::is_pod<myType>());
   }

   t_message(const std::string &object ,char ident = string);
      
   t_message(char ident = none);

   ~t_message();

private:

   template <class myType>
   void createIt(const myType &object, char ident, std::true_type)
   {
      id = ident;
      
      data = new char[sizeof(object)];
      memcpy(data,&object,sizeof(object));
   }

};


#endif
