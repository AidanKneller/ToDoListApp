- **11/17/2019** Cloned from repository and got IDE set up with openFrameworks with projectGenerator. 
- **11/19/2019** Spent time working with various OF features. 
- **11/20/2019** Set up skeleton for List and Task classes. Planning how to cleaning organize GUI and preparing for how to approach creation and handling of Lists, Tasks, etc.
- **11/24/2019** Fleshed out more of Task and List classes. Researched how to create a text box to accept input, running into issues. Next step is to get input fro screen figured out and then I cna begin making more progress. 
- **11/25/2019** Added Dashboard class to act as first screen and hold vector of Lists. Found external library to take input from the screen. Had to make a edit due to error with handling key code for '?' char. Documented in file. Next step is to add functionality to add Lists & Tasks from the screen. 
- **11/26/2019 & 11/27/2019** Worked on making objects clickable. Added two button classes, one for Tasks and one for Lists. Should enable maneuvering between the dashboard, lists, and tasks. Next steps are testing buttons and being able to maneuver between screens. 
- **11/29/2019** Buttons now clickable. Next step is to enable this for clicking through displayed tasks to see more information, and also add a loop so that buttons can be clicked sequentially, and not only once before the app terminates. 
- **11/30/2019** Added functionality for lists and task to be clicked through. Lists can be viewed, tasks can be viewed by lists, and information pertaining to individual tasks can be viewed as well. Also added back button to navigate between viewing task information and viewing lists and tasks together. Next step is to enable addition / deletion / editing of lists and tasks. Also cleaned up & commented parts of source code for myself and for final version. 
- **12/2/2019** Add button for Add New List as well as cleaned up code, and planned for next tasks to handle. Next, make creation screen for making new lists, and then use it to create a new task creation screen. Debugged and cleaned up button to text alignment. 
- **12/3/2019** List creation screen working. Lists can now be added and the program can be booted up with no lists, and filled with new lists. Added null check for lists to make sure no errors are hit when there are no lists. Next to flesh out list creation screen and apply same idea to task creation. Set up quick creation of tasks in similar style but encountered bugs. Will squash tomorrow. Cleaned up code again. No magic numbers, only numbers needed now are defined within class definitions once and can be much more easily altered. 
- **12/4/2019** Encountered and fixed issue with Tasks not showing up after being created and then changing lists. Encountering same issue with list names, they are not saved properly and do not show after navigating away from them. This is causing other issues as well. In solving the task issue, I removed the ListButton class entirely. I aim to do the same with TaskButton, and then just use ActionButton as the one Button class. 
- **12/5/2019 - 12/7/2019** Spent time hunting down bugs. Fixed issue with Lists not saving properly, was an issue with button creation and connectivity. Lists and tasks now saved properly and can be access properly. Next to work on task editing.
- **12/8/2019** Removed TaskButton class, combined functionality with Button class. Experimented with editing taks information. Implemented buttons to trigger editing methods. Planned out visual layout of editing page, will mirror task information page. 
- **12/9/2019** Add ability to edit and save task inforation (notes, name). Removed aspects of th eproject that users did not find useful.
- **12/9/2019 - 12/10/2019** Added Settings Screen, enabling you to reset the app to have zero lists, ability to check off Tasks as complete, ability to view completed tasks, and ability to remove completed lists. Added images and tweaked fonts to give UI a more finished feel. 