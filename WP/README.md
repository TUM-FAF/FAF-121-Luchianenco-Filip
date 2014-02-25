## Windows Programming Laboratories Repository

### Personal Information

**Student:** Luchianenco Filip

**Group:** FAF-121

**GitHub nickname:** [luchfilip](https://github.com/luchfilip)


### Installing required gtkmm packages

In my Laboratory works I use gtkmm, here is a short introduction about gtkmm and how you can install the dependencies in order to be able to compile the projects

gtkmm is the official C++ interface for the GUI library GTK+. Highlights include typesafe callbacks, and a comprehensive set of widgets that are easily extensible via inheritance.

In addition to that, because both the GTK+ and gtkmm are free software distributed under the GNU Library General Public License (LGPL), it allows to use both GTK+ and gtkmm for all developers, including those developing proprietary software, without paying any license fees or royalties.

The Following packages are required to be installed in Ubuntu 13.10: 

```no-highlight
sudo apt get install libglib2.0-dev libatk1.0* libatk1.0* libpango1.0-dev libcairo2-dev gdk-pixbuf2.0-0 libsigc++-2.0-dev libgtk-3-dev libcairomm-1.0-dev libpangomm-1.4-dev libatkmm-1.6-dev libgtkmm-3.0-dev
```

The following command in terminal will compile a project:

```no-highlights
g++ anyclass.cpp anyclass.h myMainClass.cpp -o anyExecutableName `pkg-config gtkmm-3.0 --cflags --libs`
./anyExecutableName 
```

