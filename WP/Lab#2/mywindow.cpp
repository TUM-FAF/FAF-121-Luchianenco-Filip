#include "mywindow.h"
#include <gtkmm/stock.h>
#include <iostream>

MyWindow::MyWindow()
: m_Box(Gtk::ORIENTATION_VERTICAL),
  d_Box(Gtk::ORIENTATION_VERTICAL),
  h1_Box(Gtk::ORIENTATION_HORIZONTAL),
  h2_Box(Gtk::ORIENTATION_HORIZONTAL),
  h3_Box(Gtk::ORIENTATION_HORIZONTAL)
{
  set_title("TODO List");
  set_default_size(600, 400);
 // set_position(Gtk::WIN_POS_CENTER_ALWAYS);

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
  m_refActionGroup->add(Gtk::Action::create("EditCopy", Gtk::Stock::COPY),
          sigc::mem_fun(*this, &MyWindow::on_menu_others));
  m_refActionGroup->add(Gtk::Action::create("EditPaste", Gtk::Stock::PASTE),
          sigc::mem_fun(*this, &MyWindow::on_menu_others));
  m_refActionGroup->add(Gtk::Action::create("EditSomething", "Something"),
          Gtk::AccelKey("<control>S"),
          sigc::mem_fun(*this, &MyWindow::on_menu_others));


  //Choices menu, to demonstrate Radio items
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
          sigc::mem_fun(*this, &MyWindow::on_menu_others) );

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

    d_Box.add(h1_Box);

    h1_Box.set_vexpand(false);

    topText->set_text("Make you own TODO List");
    h1_Box.pack_start(*topText, true, true, 5);

    todo_entry->set_max_length(50);
    todo_entry->set_text("add Items");
    set_focus_child(*todo_entry);
    todo_entry->set_text(todo_entry->get_text() + " to TODO List");
    todo_entry->select_region(0, todo_entry->get_text_length());

    d_Box.add(h2_Box);
    h2_Box.set_vexpand(false);
    h2_Box.pack_start(*todo_entry, true, true, 5);

    b_add->signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_addEntry_clicked));

    h2_Box.pack_start(*b_add, false, true, 5);

    //Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.add(m_TreeView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

      //Create the Tree model:
  m_refTreeModel = Gtk::ListStore::create(m_Columns);
  m_TreeView.set_model(m_refTreeModel);

  //Create the Tree model:
  m_refTreeModel = Gtk::ListStore::create(m_Columns);
  m_TreeView.set_model(m_refTreeModel);

  //Fill the TreeView's model
  Gtk::TreeModel::Row row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 1;
  row[m_Columns.m_col_name] = "Billy Bob";
  row[m_Columns.m_col_number] = 10;
  row[m_Columns.m_col_percentage] = 15;

  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 2;
  row[m_Columns.m_col_name] = "Joey Jojo";
  row[m_Columns.m_col_number] = 20;
  row[m_Columns.m_col_percentage] = 40;

  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 3;
  row[m_Columns.m_col_name] = "Rob McRoberts";
  row[m_Columns.m_col_number] = 30;
  row[m_Columns.m_col_percentage] = 70;

  //Add the TreeView's view columns:
  //This number will be shown with the default numeric formatting.
  m_TreeView.append_column("ID", m_Columns.m_col_id);
  m_TreeView.append_column("Name", m_Columns.m_col_name);

  m_TreeView.append_column_numeric("Formatted number", m_Columns.m_col_number,
          "%010d" /* 10 digits, using leading zeroes. */);

  //Display a progress bar instead of a decimal number:
  Gtk::CellRendererProgress* cell = Gtk::manage(new Gtk::CellRendererProgress);
  int cols_count = m_TreeView.append_column("Some percentage", *cell);
  Gtk::TreeViewColumn* pColumn = m_TreeView.get_column(cols_count - 1);
  if(pColumn)
  {
    pColumn->add_attribute(cell->property_value(), m_Columns.m_col_percentage);
  }

  //Make all the columns reorderable:
  //This is not necessary, but it's nice to show the feature.
  //You can use TreeView::set_column_drag_function() to more
  //finely control column drag and drop.
  for(guint i = 0; i < 2; i++)
  {
    Gtk::TreeView::Column* pColumn = m_TreeView.get_column(i);
    pColumn->set_reorderable();
  }

    d_Box.add(h3_Box);



    h3_Box.set_vexpand(true);
    //h2_Box.set_hexpand(true);

  h3_Box.pack_start(m_ScrolledWindow, true, true, 5);

  show_all_children();
}

MyWindow::~MyWindow()
{
}

void MyWindow::on_addEntry_clicked() {

}

void MyWindow::on_menu_file_quit()
{
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
                break;
            }
  //hide(); //Closes the main window to stop the app->run().
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


