#ifndef GAME_WINDOW_H_INCLUDED
#define GAME_WINDOW_H_INCLUDED

#include <boost/utility.hpp>

#include <gtkmm.h>
#include <SFML/Graphics.hpp>

struct inputData
{
   float position[3];
   float translation[3];
   float textcord[2];
   float rotation;

   float buffer[7];
};

inline
void *offset(int floatNum)
{
   return (void *)(sizeof(float) * floatNum);
}


class t_gameWindow : boost::noncopyable
{
public:
   t_gameWindow(); //Do not do anything
   t_gameWindow(Gtk::DrawingArea *s);
   ~t_gameWindow();

   void start();

private:


   void initializeGL();
   bool onExpose(GdkEventExpose *event);

   Gtk::DrawingArea *drawingArea;
   sf::Window App;

   int frames;
   unsigned int textures[1];

   unsigned int vertexBuffer;
   unsigned int indexBuffer;

   unsigned short indexes[60];
   long theTime;
   double rotation;
   inputData vertexes[40];

};




#endif
