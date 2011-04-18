#ifndef TANKS_GUI_H_INCLUDED
#define TANSK_GUI_H_INCLUDED

#include <boost/utility.hpp>
#include "shared.h"

#include <gtkmm.h>

class t_tanksGui : boost::noncopyable
{
public:
   t_tanksGui(t_sharedData theSharedData);
   ~t_tanksGui();

   void run();

private:
   t_sharedData sharedData;
   Glib::RefPtr<Gtk::Builder> builder;


   bool onIO(Glib::IOCondition cond);
   bool onMessage(const t_message &mess);

   void onButton();
};

#endif
