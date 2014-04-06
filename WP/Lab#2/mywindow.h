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
    Gtk::Button *b_add = Gtk::manage(new Gtk::Button("Add New Task"));
    Gtk::Button *b_saveEdit = Gtk::manage(new Gtk::Button("Save Edit"));
    Gtk::Button *b_delete = Gtk::manage(new Gtk::Button("Delete Task"));
    Gtk::TreeViewColumn* pColumn = Gtk::manage(new Gtk::TreeViewColumn);
    Glib::RefPtr<Gtk::AccelGroup> group = Gtk::AccelGroup::create();
    Glib::RefPtr<Gtk::Adjustment> m_adjustment;
  virtual ~MyWindow();

protected:
  //Signal handlers:
  void on_menu_file_new_generic();
  void on_menu_file_quit();
  void on_menu_others();

  void on_menu_choices_one();
  void on_menu_choices_two();
  void on_addEntry_clicked();
  void add_entry(Glib::ustring task, int percentage);
  void on_help_clicked();
  void onSaveEdit_clicked();
  void on_selection_changed();
  void on_delete_clicked();
  void on_text_changed();

  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns()
    { add(m_col_id); add(m_col_percentage); add(m_col_name);}

    Gtk::TreeModelColumn<unsigned int> m_col_id;
    Gtk::TreeModelColumn<int> m_col_percentage;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
  };

  ModelColumns m_Columns;

  int count;
  bool any_row_selected = false;

  //Child widgets:
  Gtk::Box m_Box;
  Gtk::Box d_Box;
  Gtk::Box h1_Box;
  Gtk::Box h2_Box;
  Gtk::Box h3_Box;
  Gtk::EventBox event_box;
  Gtk::Label m_Label;
  Gtk::Scale m_HScale;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
  Gtk::TreeModel::Row row;

  Glib::RefPtr<Gtk::TreeSelection> m_refTreeSelection;
  Glib::RefPtr<Gtk::UIManager> m_refUIManager;
  Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;
  Glib::RefPtr<Gtk::RadioAction> m_refChoiceOne, m_refChoiceTwo;
};

#endif //MYWINDOW_H
