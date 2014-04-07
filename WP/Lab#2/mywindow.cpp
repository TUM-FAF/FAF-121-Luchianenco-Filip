#include "mywindow.h"
#include <gtkmm/stock.h>
#include <iostream>

MyWindow::MyWindow()
: m_Box(Gtk::ORIENTATION_VERTICAL),
  d_Box(Gtk::ORIENTATION_VERTICAL),
  h1_Box(Gtk::ORIENTATION_HORIZONTAL),
  h2_Box(Gtk::ORIENTATION_HORIZONTAL),
  h3_Box(Gtk::ORIENTATION_HORIZONTAL),

  m_adjustment( Gtk::Adjustment::create(0, 0, 100, 1, 1)),
  m_HScale(m_adjustment, Gtk::ORIENTATION_HORIZONTAL)
{
  set_title("TODO List");
  set_default_size(800, 400);
  set_icon_from_file(iconpath);

  //set_position center is bugged.
  //see details here: https://www.youtube.com/watch?v=UDSV1Q7-5R4
  //set_position(Gtk::WIN_POS_CENTER_ALWAYS);

  // put a MenuBar at the top of the box and other stuff below it.
  add(m_Box);

  //Create actions for menus and toolbars:
  m_refActionGroup = Gtk::ActionGroup::create();

  //File|New sub menu:
  m_refActionGroup->add(Gtk::Action::create("FileNewStandard",
              Gtk::Stock::NEW, "_New", "Create a new file"),
          sigc::mem_fun(*this, &MyWindow::on_menu_file_new_generic));

  m_refActionGroup->add(Gtk::Action::create("FileNewFile",
              Gtk::Stock::NEW, "New File", "Create a new foo"),
          sigc::mem_fun(*this, &MyWindow::on_menu_file_new_generic));

  m_refActionGroup->add(Gtk::Action::create("FileNewWindow",
              Gtk::Stock::NEW, "_New Window", "Create a new goo"),
          sigc::mem_fun(*this, &MyWindow::on_menu_file_new_generic));

  //File menu:
  m_refActionGroup->add(Gtk::Action::create("FileMenu", "File"));
  //Sub-menu.
  m_refActionGroup->add(Gtk::Action::create("FileNew", Gtk::Stock::NEW));
  m_refActionGroup->add(Gtk::Action::create("FileQuit", Gtk::Stock::QUIT),
          sigc::mem_fun(*this, &MyWindow::on_menu_file_quit));

  //Edit menu:
  m_refActionGroup->add(Gtk::Action::create("EditMenu", "Edit"));
  m_refActionGroup->add(Gtk::Action::create("EditCopy", "Copy", "Ctrl+C"));
  m_refActionGroup->add(Gtk::Action::create("EditPaste", "Paste", "Ctrl+V"));
  m_refActionGroup->add(Gtk::Action::create("EditSomething", "Add Entry"),
          Gtk::AccelKey("<control>S"), sigc::mem_fun(*this, &MyWindow::on_addEntry_clicked));


  //Choices menu for Radio items
  m_refActionGroup->add( Gtk::Action::create("ChoicesMenu", "Choices") );
  Gtk::RadioAction::Group group_userlevel;
  m_refChoiceOne = Gtk::RadioAction::create(group_userlevel, "ChoiceOne", "One");
  m_refActionGroup->add(m_refChoiceOne,
          sigc::mem_fun(*this, &MyWindow::on_menu_choices_one) );
  m_refChoiceTwo = Gtk::RadioAction::create(group_userlevel, "ChoiceTwo", "Two");
  m_refActionGroup->add(m_refChoiceTwo,
          sigc::mem_fun(*this, &MyWindow::on_menu_choices_two) );

  //Help menu:
  m_refActionGroup->add( Gtk::Action::create("HelpMenu", "Help") );
  m_refActionGroup->add( Gtk::Action::create("HelpAbout", Gtk::Stock::HELP),
          sigc::mem_fun(*this, &MyWindow::on_help_clicked) );

  m_refUIManager = Gtk::UIManager::create();
  m_refUIManager->insert_action_group(m_refActionGroup);

  add_accel_group(m_refUIManager->get_accel_group());

  //Layout the actions in a menubar and toolbar:
  Glib::ustring ui_info =
        "<ui>"
        "  <menubar name='MenuBar'>"
        "    <menu action='FileMenu'>"
        "      <menu action='FileNew'>"
        "        <menuitem action='FileNewStandard'/>"
        "        <menuitem action='FileNewFile'/>"
        "        <menuitem action='FileNewWindow'/>"
        "      </menu>"
        "      <separator/>"
        "      <menuitem action='FileQuit'/>"
        "    </menu>"
        "    <menu action='EditMenu'>"
        "      <menuitem action='EditCopy'/>"
        "      <menuitem action='EditPaste'/>"
        "      <menuitem action='EditSomething'/>"
        "    </menu>"
        "    <menu action='ChoicesMenu'>"
        "      <menuitem action='ChoiceOne'/>"
        "      <menuitem action='ChoiceTwo'/>"
        "    </menu>"
        "    <menu action='HelpMenu'>"
        "      <menuitem action='HelpAbout'/>"
        "    </menu>"
        "  </menubar>"
        "  <toolbar  name='ToolBar'>"
        "    <toolitem action='FileNewStandard'/>"
        "    <toolitem action='FileQuit'/>"
        "  </toolbar>"
        "</ui>";

  try
  {
    m_refUIManager->add_ui_from_string(ui_info);
  }
  catch(const Glib::Error& ex)
  {
    std::cerr << "building menus failed: " <<  ex.what();
  }

  //Get the menubar and toolbar widgets, and add them to a container widget:
  Gtk::Widget* pMenubar = m_refUIManager->get_widget("/MenuBar");
  if(pMenubar)
    m_Box.pack_start(*pMenubar, Gtk::PACK_SHRINK);

  Gtk::Widget* pToolbar = m_refUIManager->get_widget("/ToolBar") ;
  if(pToolbar)
    m_Box.pack_start(*pToolbar, Gtk::PACK_SHRINK);

    // Add the box which will contain all window elements below menu
    m_Box.add(d_Box);


/*  //initially it was supposed to be a text between menu and entry. Later it was removed
    d_Box.add(h1_Box);
    h1_Box.set_vexpand(false);
    topText->set_text("Make you own TODO List");
    h1_Box.pack_start(*topText, true, true, 5);
*/
    //add h2_Box to main box
    d_Box.add(h2_Box);
    h2_Box.set_vexpand(false);

   //set and add entry to box
    todo_entry->set_text("add Items");
    set_focus_child(*todo_entry);
    todo_entry->set_text(todo_entry->get_text() + " to TODO List");
    todo_entry->select_region(0, todo_entry->get_text_length());
    todo_entry->signal_changed().connect(sigc::mem_fun(*this, &MyWindow::on_text_changed));
    h2_Box.pack_start(*todo_entry, true, true, 5);

    //add scrollbar percentage
    m_HScale.set_digits(1);
    m_HScale.set_value_pos(Gtk::POS_TOP);
    m_HScale.set_draw_value();
    m_HScale.set_digits(0);
    m_HScale.signal_value_changed().connect(sigc::mem_fun(*this, &MyWindow::on_scale_changed));
    h2_Box.pack_start(m_HScale, true, true, 5);

    //add Entry button
    b_add->signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_addEntry_clicked));
    h2_Box.pack_start(*b_add, false, true, 5);

    Glib::ustring someTask = "some task";
    //add Button which saves editing
    b_saveEdit->signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::onSaveEdit_clicked));
    b_saveEdit->set_sensitive(false);
    h2_Box.pack_start(*b_saveEdit, false, true, 5);

    b_delete->signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_delete_clicked));
    b_delete->set_sensitive(false);
    h2_Box.pack_start(*b_delete, false, true, 5);

    //Add the TreeView, inside a ScrolledWindow:
  m_ScrolledWindow.add(m_TreeView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

      //Create the Tree model:
    m_refTreeModel = Gtk::ListStore::create(m_Columns);

    m_TreeView.set_model(m_refTreeModel);


  //Fill the TreeView's model
  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 1;
  row[m_Columns.m_col_percentage] = 15;
  row[m_Columns.m_col_name] = "Buy milk";

  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 2;
  row[m_Columns.m_col_percentage] = 40;
  row[m_Columns.m_col_name] = "Do Laboratory #2 &#3 on WP";

  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 3;
  row[m_Columns.m_col_percentage] = 70;
  row[m_Columns.m_col_name] = "Do other laboratory Works";

    //set selection listener on list
    m_refTreeSelection = m_TreeView.get_selection();
    m_refTreeSelection->signal_changed().connect( sigc::mem_fun(*this, &MyWindow::on_selection_changed));
  //set counter for rows
  count = 3;
  //Add the TreeView's view columns:
  //This number will be shown with the default numeric formatting.
  m_TreeView.append_column("ID", m_Columns.m_col_id);

  //Display a progress bar instead of a decimal number:
  Gtk::CellRendererProgress* cell = Gtk::manage(new Gtk::CellRendererProgress);
  int cols_count = m_TreeView.append_column("Task Completed", *cell);
  pColumn = m_TreeView.get_column(cols_count - 1);
  if(pColumn)
  {
    pColumn->add_attribute(cell->property_value(), m_Columns.m_col_percentage);
  }

  m_TreeView.append_column("Task Description", m_Columns.m_col_name);

  //Make all the columns reorderable:
  for(guint i = 0; i <= 2; i++)
  {
    Gtk::TreeView::Column* pColumn = m_TreeView.get_column(i);
    pColumn->set_reorderable();
  }

    d_Box.add(h3_Box);

    h3_Box.set_vexpand(true);

  h3_Box.pack_start(m_ScrolledWindow, true, true, 5);

  show_all_children();
}

MyWindow::~MyWindow()
{
}

void MyWindow::on_addEntry_clicked() {
    count++;

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = count;
    row[m_Columns.m_col_name] = todo_entry->get_text();
    row[m_Columns.m_col_percentage] = m_HScale.get_value();
}

void MyWindow::add_entry(Glib::ustring task, int percentage)
{
  std::cout << task << std::endl;
    std::cout << percentage << std::endl;

}

void MyWindow::on_menu_file_quit()
{
             //Gtk::MESSAGE_ERROR
         Gtk::MessageDialog quitDialog("Are you sure you want to Quit?",
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
                break;
            }
}

void MyWindow::on_menu_file_new_generic()
{
   std::cout << "A File|New menu item was selected." << std::endl;
}

void MyWindow::on_menu_others()
{
  std::cout << "A menu item was selected." << std::endl;
}

void MyWindow::on_menu_choices_one()
{
  Glib::ustring message;
  if(m_refChoiceOne->get_active())
    message = "Choice 1 was selected.";
  else
    message = "Choice 1 was deselected";

  std::cout << message << std::endl;
}

void MyWindow::on_menu_choices_two()
{
  Glib::ustring message;
  if(m_refChoiceTwo->get_active())
    message = "Choice 2 was selected.";
  else
    message = "Choice 2 was deselected";

  std::cout << message << std::endl;
}

void MyWindow::on_selection_changed()
{
    any_row_selected = true;

    b_saveEdit->set_sensitive(true);
    b_delete->set_sensitive(true);

    Gtk::TreeModel::iterator iter = m_refTreeSelection->get_selected();
    Gtk::TreeModel::Row row = *iter;
    //get data from selected row
    Glib::ustring task_string = row.get_value(m_Columns.m_col_name);
    int selected_percentage = row.get_value(m_Columns.m_col_percentage);
    unsigned int selected_id = row.get_value(m_Columns.m_col_id);

    todo_entry->set_text(task_string);
    double scale_value = (double) selected_percentage;
    m_HScale.set_value(scale_value);


std::cout << selected_id << std::endl;
}

void MyWindow::onSaveEdit_clicked()
{
    b_saveEdit->set_sensitive(false);

    Gtk::TreeModel::iterator iter = m_refTreeSelection->get_selected();
    Gtk::TreeModel::Row row = *iter;

    Glib::ustring new_entry = todo_entry->get_text();
    row.set_value(m_Columns.m_col_name, new_entry);
    int new_percentage = m_HScale.get_value();
    row.set_value(m_Columns.m_col_percentage, new_percentage);

 std::cout << new_percentage << std::endl;
}

void MyWindow::on_delete_clicked()
{
    Gtk::TreeModel::iterator store_iter = m_refTreeSelection->get_selected();
    m_refTreeModel->erase(store_iter);
}

void MyWindow::on_text_changed()
{
    bool is_button_active = b_saveEdit->get_sensitive();

    if(any_row_selected && !is_button_active) {
        b_saveEdit->set_sensitive(true);
    }

     std::cout << "text has changed" << std::endl;
}

void MyWindow::on_scale_changed()
{
    bool is_button_active = b_saveEdit->get_sensitive();

    if(any_row_selected && !is_button_active) {
    b_saveEdit->set_sensitive(true);
    }
}

void MyWindow::on_help_clicked()
{
    Gtk::MessageDialog dlg("Help", false,
            Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dlg.set_title("Help Dialog");
    dlg.set_secondary_text("Add items to your TODO list by writing the task in the entry box, and then press Ctrl+S or button Add. ");
    dlg.run();
}


