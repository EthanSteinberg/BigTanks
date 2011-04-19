#include "tanksGui.h"

#include "shared.h"

t_tanksGui::t_tanksGui(t_sharedData theSharedData) : sharedData(theSharedData)
{
   sharedData.guiQueue.closeWrite();
   sharedData.midQueue.closeRead();
}

t_tanksGui::~t_tanksGui()
{}

void t_tanksGui::run()
{
   builder =  Gtk::Builder::create_from_file("../res/layout.glade");

   Gtk::Window *wind;
   builder->get_widget("MainWindow",wind);

   Gtk::Button *but;
   builder->get_widget("aboutButton",but);
   but->signal_clicked().connect(sigc::mem_fun(this,&t_tanksGui::onButton));

   Glib::signal_io().connect(sigc::mem_fun(this,&t_tanksGui::onIO),sharedData.guiQueue.getWaitFd(),Glib::IO_IN | Glib::IO_HUP);
   Gtk::Main::run(*wind);
}

bool t_tanksGui::onIO(Glib::IOCondition cond)
{
   bool state = true;

   if (cond & Glib::IO_IN)
   {
      t_message mess = sharedData.guiQueue.pop();

      state = onMessage(mess);
   }

   if (cond & Glib::IO_HUP)
   {
      puts("The pipe has closed");
      return false;
   }

   return state;
}

void t_tanksGui::onButton()
{
   t_message text(t_message::string,"And I can talk back too...");
   sharedData.midQueue.push(text);
}
