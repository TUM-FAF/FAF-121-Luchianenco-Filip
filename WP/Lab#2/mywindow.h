#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <gtkmm.h>

class MyWindow : public Gtk::Window
{
public:
  MyWindow();
  // constants used in dialog responses
    static const int yes_response = -8;
    static const int no_response = -9;
    static const int ok_response = -5;

    Gtk::Label *topText = Gtk::manage(new Gtk::Label());
    Gtk::Label *topTextRight = Gtk::manage(new Gtk::Label());
    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid);
    Gtk::Entry *todo_entry = Gtk::manage(new Gtk::Entry());
    Gtk::Button *b_add = Gtk::manage(new Gtk::Button("Add Entry"));
  virtual ~MyWindow();

protected:
  //Signal handlers:
  void on_menu_file_new_generic();
  void on_menu_file_quit();
  void on_menu_others();

  void on_menu_choices_one();
  void on_menu_choices_two();

  void on_addEntry_clicked();

  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns()
    { add(m_col_id); add(m_col_name); add(m_col_number); add(m_col_percentage);}

    Gtk::TreeModelColumn<unsigned int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    Gtk::TreeModelColumn<short> m_col_number;
    Gtk::TreeModelColumn<int> m_col_percentage;
  };

  ModelColumns m_Columns;

  //Child widgets:
  Gtk::Box m_Box;
  Gtk::Box d_Box;
  Gtk::Box h1_Box;
  Gtk::Box h2_Box;
  Gtk::Box h3_Box;

  Gtk::Label m_Label;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

  Glib::RefPtr<Gtk::UIManager> m_refUIManager;
  Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;
  Glib::RefPtr<Gtk::RadioAction> m_refChoiceOne, m_refChoiceTwo;
};

#endif //MYWINDOW_H
