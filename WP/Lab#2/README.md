### Laboratory Work #2 Still in progress...


## Mandatory Objectives
* Display a dialog box on some event (ex. on clicking some button) 
* Add a system menu to your application with at least 3 items (add actions to that items)
* Add a scroll bar that will change any visible parameter of any other element (color of a text)
* Hook keyboard input. Add 2 custom events for 2 different keyboard combinations (ex. change window background on ctrl+space) 

## Objectives With Points
* Add a listbox and attach some events when any element is accessed (clicked) **(2 pt)**
* Add 2 scroll bars that will manage main window size or position **(1 pt)**
* Customize your application by adding an icon and using different cursor in application **(1 pt)**
* Use a scroll bar to scroll through application working space. Scroll should appear only when necessary (eg. when window width is smaller than 300px) **(1 pt)**


#### Here is a screenshot of main application window:
![App_screenshot](http://i.imgur.com/iwBNE2D.png)

####  Display a dialog box on some event & add a system menu with actions to items & Hook keyboard input

I implemented an "Are you sure you want to Quit?" dialog. It is triggered on:
* File > Quit 
* Ctrl + Q
* Click on red quit button

![quit_dialog](http://i.imgur.com/1Mx1TzW.png)

Also the Help Dialog, which is triggered from top menu or F1:

![help_dialog](http://i.imgur.com/gycMV3k.png)

#### Add a listbox and attach some events when any element is accessed

The Selected Task is shown in the entry box together with the percentage when selected.

![listbox](http://i.imgur.com/ZxArgel.png)

#### Use a scroll bar to scroll through application working space. Scroll should appear only when necessary

Scrollbars appear when items do not fit inside the window

![scrollbars](http://i.imgur.com/fjiF6dp.png)

#### Additional Features

There are more features which could not be shown in screenshots, so here is a video:

https://www.youtube.com/watch?v=ob12A8gjJHI


### Conclusion

In this laboratory work I understood how to implement more specific features to an application in gtkmm. Unfortunatelly, gtk's support is extremelly awful, so I had to read a lot of documentation in order to understand how things work rather than implementing the solution already found by someone else before me. In this application I arranged the elements better, in another way, which gives the possibility to position the elements and write their properties easier. 

