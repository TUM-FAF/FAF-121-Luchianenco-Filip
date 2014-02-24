#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <gtkmm.h>

class mywindow : public Gtk::Window
{
    public:
    // constants used in dialog responses
    static const int yes_response = -8;
    static const int no_response = -9;
    static const int ok_response = -5;

    // declare text elements(labels)
    Gtk::Label *lusername = Gtk::manage(new Gtk::Label());
    Gtk::Label *lpassword = Gtk::manage(new Gtk::Label());

    // declare text imputs
    Gtk::Entry *eusername = Gtk::manage(new Gtk::Entry());
    Gtk::Entry *epassword = Gtk::manage(new Gtk::Entry());
    GdkColor color;
    GtkRcStyle *rc_style;
        mywindow();
        virtual ~mywindow();
    protected:
    void on_login_click(Gtk::Entry *username, Gtk::Entry *userPass);
    void run_error_dialog(Glib::ustring msg);
    void on_quit_click();
    void check_login_dialog();
    bool quitting();
    private:

// default dialog response ids
//      RESPONSE_NONE = -1,
//      RESPONSE_REJECT = -2,
//      RESPONSE_ACCEPT = -3,
//      RESPONSE_DELETE_EVENT = -4,
//      RESPONSE_OK = -5,
//      RESPONSE_CANCEL = -6,
//      RESPONSE_CLOSE = -7,
//      RESPONSE_YES = -8,
//      RESPONSE_NO = -9,
//      RESPONSE_APPLY = -10,
//      RESPONSE_HELP = -11
};

#endif // MYWINDOW_H
