#include <cstdio>
#include <gtkmm.h>

#include <unistd.h>

#include <boost/bind.hpp>
#include <boost/function.hpp>

#include <myQueue.h>

void butPush(Gtk::Dialog *dio)
{
   dio->run();
}

void *wrap_func(void *the_func)
{
   boost::function<void ()> *func = reinterpret_cast<boost::function<void ()> * >(the_func);

   (*func)();
   delete func;

   return NULL;
}

void start_func(t_myQueue que)
{
   printf("The thread was created\n");

   que.closeRead();

   t_message newMes = t_message(std::string("Hello world better version"));

   que.push(newMes);
}

bool readIt(Glib::IOCondition cond, Gtk::Dialog *dio, t_myQueue &que)
{
   if (cond & Glib::IO_IN)
   {
      t_message blah = que.pop();

      if (blah.id == t_message::string)
      {
         char *str = reinterpret_cast<char *>(blah.data);
         printf("The thing was called %s\n",str);
      }

      else
      {
         printf("WTF, wront id\n");
         char *str = reinterpret_cast<char *>(blah.data);
         printf("The thing was called %s\n",str);
      }

      dio->show();
   }

   if (cond & Glib::IO_HUP)
   {
      printf("Wow a loss of connection\n");

      return false;
   }

   if (!(cond & (Glib::IO_HUP | Glib::IO_IN)))
   {
      printf("Something else entirely\n");
   }


   return true;
}

int main(int argv, char **argc)
{
   Gtk::Main main(argv,argc);
   Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("../res/layout.glade");


   Gtk::Window *wind;
   builder->get_widget("MainWindow",wind);

   Gtk::Button *but;
   builder->get_widget("button1",but);

   Gtk::Dialog *dio;
   builder->get_widget("aboutdialog1",dio);

   but->signal_clicked().connect(sigc::bind(sigc::ptr_fun(butPush),dio));

   t_myQueue que;


   pthread_t thread;

   if (pthread_create(&thread,NULL,wrap_func,new boost::function<void ()>(boost::bind(start_func,que))))
   {
      perror("pthread_create: ");
   }

   que.closeWrite();

   Glib::signal_io().connect(sigc::bind(sigc::ptr_fun(readIt),dio,que),que.getWaitFd(),Glib::IO_IN | Glib::IO_HUP);
   main.run(*wind);

   printf("Hello world\n");
   return 0;
}
