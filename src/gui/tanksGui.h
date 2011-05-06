#ifndef TANKS_GUI_H_INCLUDED
#define TANSK_GUI_H_INCLUDED

#include <boost/utility.hpp>
#include "shared.h"
#include "gameWindow.h"

#include <gtkmm.h>
#include <SFML/Graphics.hpp>
class t_tanksGui : boost::noncopyable
{
public:
   t_tanksGui(t_sharedData theSharedData);
   ~t_tanksGui();

   void run();

private:
   t_sharedData sharedData;
   Glib::RefPtr<Gtk::Builder> builder;

   Gtk::Window *graphicsWindow;

   Gtk::DrawingArea *drawingArea;


   t_gameWindow *gameWindow;


bool onExpose(GdkEventExpose* event);

   bool onIO(Glib::IOCondition cond);
   void stuff();
   bool onMessage(const t_message &mess);

   void onButton();
   void onGameOpened();
};

#endif
