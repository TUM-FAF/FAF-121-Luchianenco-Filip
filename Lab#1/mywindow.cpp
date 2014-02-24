#include <iostream>
#include "mywindow.h"

mywindow::mywindow()
{
    set_default_size(400, 100);
    set_title("Lab#1 Login to WP");
    set_position(Gtk::WIN_POS_CENTER_ALWAYS);

    //signal_quit().connect (sigc::ptr_fun(&quitting));
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // create grid to place items
    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid);
    grid->set_border_width(10);
    grid->set_row_spacing(5);
    // add the grid to the box
    vbox->add(*grid);

    // set text to text element
    lusername->set_text("Username");
    // add username label to the grid on pos 0(x) 0(y) , span 1 cell wide, and 1 down
    grid->attach(*lusername, 0, 0, 1, 1);
    // make text element bold and set it
    lpassword->set_markup("<b>Password: </b>");
    grid->attach(*lpassword, 0, 1, 1, 1);

    //setup username imput
    eusername->set_hexpand(true);
    //on mouse hover, a small tip appears
    eusername->set_tooltip_text("username: filip");
    eusername->set_max_length(5);
    grid->attach(*eusername, 1, 0, 2, 1);

    // setup password imput
    epassword->set_hexpand(true);
    epassword->set_tooltip_text("password: admin");
    //"password mode"
    epassword->set_visibility(false);
    grid->attach(*epassword, 1, 1, 2, 1);

    //create quit button
    Gtk::Button *bquit = Gtk::manage(new Gtk::Button("Quit"));
    bquit->signal_clicked().connect(sigc::mem_fun(*this, &mywindow::on_quit_click));
    grid->attach(*bquit, 1, 2, 1, 1);

    // create login button
    Gtk::Button *blogin = Gtk::manage(new Gtk::Button("Login"));
    blogin->signal_clicked().connect(sigc::bind<Gtk::Entry*, Gtk::Entry*>
                (sigc::mem_fun(*this, &mywindow::on_login_click),
                                        eusername, epassword));
    grid->attach(*blogin, 2, 2, 1, 1);

    // show all elements
    vbox->show_all();

}

mywindow::~mywindow()
{
    //dtor
}

bool quitting () // called when Gtk::Main quits
{
    Gtk::MessageDialog("Goodbye").run();
    return true;
}

void mywindow::on_login_click(Gtk::Entry *username, Gtk::Entry *password) {
        // check username and passoword for match
        if(username->get_text().compare("filip") == 0 &&
            password->get_text().compare("admin") == 0) {
                // reset to default in case labels are red
                lusername->set_markup("Username: ");
                lpassword->override_color (Gdk::RGBA("black"), Gtk::STATE_FLAG_NORMAL);
                check_login_dialog();
            } else {
                // we can use set_markup to change style of label, also this lets us
                // costumize parts of labels, rather than change the whole label's style
                lusername->set_markup("<b><span color='red'>Username: </span></b>");
                // or we can use override_color
                lpassword->override_color (Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
                // call function with a parameter
                run_error_dialog("Login Failed");
            }
    }
// create a default dialog to use
void mywindow::run_error_dialog(Glib::ustring msg) {
         Gtk::MessageDialog dlg(msg, false,
                    Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, true);
                dlg.set_title("Login Dialog");
                dlg.set_secondary_text("Oh Cmon'! there are hints for text imputs on mouse hover");
                dlg.run();
    }

void mywindow::check_login_dialog() {
         Gtk::MessageDialog dlg("Login Successfully", false,
                    Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
                dlg.set_title("Login Dialog");
                dlg.set_secondary_text("Congrats! If you hit ok, the text imputs will reset");
                // save the return result
                int result = dlg.run();
                 switch(result) {
                        case(ok_response):
                            // reset text imputs to default
                            eusername->set_text("");
                            epassword->set_text("");
                            break;
                        default:
                            break;
                    }
    }
void mywindow::on_quit_click() {
         //Gtk::MESSAGE_ERROR
         Gtk::MessageDialog quitDialog("Are you sure you want to quit",
                                        false,
                                        Gtk::MESSAGE_ERROR,
                                        Gtk::BUTTONS_YES_NO,
                                        true);
            quitDialog.set_title("Quit Dialog");
            //save dialog result in order to handle the click
            int result = quitDialog.run();
        switch(result) {
            // default YES response id
            case(yes_response):
                hide();
                break;
            // default NO response id
            case(no_response):
                // hide previews dialog, or it gets messy
                quitDialog.hide();
                Gtk::MessageDialog dlg("Yaay", false,
                    Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
                dlg.set_title("Quit Dialog");
                dlg.set_secondary_text("This is a secondary text. Also the default size has be changed and dialog's window is resizable, by default a dialog is not resizable");
                // enable resize, by default the dialog is not resizable
                dlg.set_resizable(true);
                dlg.set_default_size(400, 100);
                dlg.run();
            break;
        }


    }
