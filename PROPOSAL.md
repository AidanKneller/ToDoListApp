<!-- Write your proposal here! Make sure to use properly-formatted Markdown! -->


# **Final Project Proposal - To Do List Application**


## Idea
For my final project, I would like to build a full fledged To Do List application. Essentially, this application would allow users to create multiple To Do lists, each with multiple tasks inside. Users would be able to check off completed tasks, add and remove tasks, set due date and times for tasks, and organize / view tasks based on which are due soonest and which were last modified. This app would also have a front end portion to it, which would be an interactive interface by which users could select what they wanted to do. Specically, I would like to have an interface with multiple buttons for options like "Add List", "Add Task", and so on. I would also like to allow the application to not just be a "one and done" app. I would like to be able to save To Do lists by writing them out into JSON files, and be able to bring them back in at a later time by reading them in from JSON files.

## Background/Personal Investment
As far background knowledge and invested interest on this topic, I am a person who loves making lists and completing tasks. I've used a lot of task keeping and to do list apps, many of which are great and many of which are terrible. I think it would interesting to get a developers view of apps like this, as well as apply my skills from this class in a more personal context. I've also been excited to try some more front end, UI/UX style programming. That, combined with having tried many to do list apps, I am excited to build one that is functional, practicial, and matches my personal wants and needs for a to do list app. 

## Possible Stretch Goals
Should I have more time for this project, if I am ahead of schedule, it would be interesting to add the ability for users to upload images and audio files to tasks. If a user needs to, say, make a task called "Do Math Homework", but they don't want to put the intricate detaisl of the task in, they may simply upload an image of the specific assignment. Or, say the user needs to add a melody to a song they wrote, they may put that task in and attach an audio file of said melody to remeber later. It would also be a fun addition to add a Light and Dark mode, since that is popular and nice to have nowadays. 

## External Libraries
Along with ofxGui, I want to use external libraries like ofxCenteredTrueTypeFont / ofxSmartFont to work with typography within the UI, and ofxCairo for drawing to the screen. I need to do more research on how openFrameworks works and what things can be done with it to narrow down more specific libraries to use, but I will certainly be using libraries for the sake of writing information to the screen, adding buttons and enabling text boxes on the screen. 
  
 https://github.com/armadillu/ofxCenteredTrueTypeFont
 https://github.com/braitsch/ofxSmartFont

Should I incorporate audio and image uploading, I could use ofxLibsndfileRecorder, an external library that records sound in various formats. 

https://github.com/angeloseme/ofxLibsndfileRecorder


## Timeline by Week
* *By the end of Week 1*, I will have classes made for List, Task, and Reminder, task management methods written, as well as the JSON reading and writing implemented. 
* *By the end of Week 2*, I will have a rough version of the UI created.
* *By the end of Week 3*, I will have polished the UI and have it looking visually appealing. 
* *By the end of Week 4*, I will have ensured that the application works and writies to and reads from JSON. 


# **Edited Proposal Post Project**

## Idea
My idea remained the same, but after doing some UX testing and picking the brains of peers, I realized some of the functions I wanted to implement would not have been useful. I decided to pivot from adding functionality that other apps did not have to focusing on making something clean, simple, and easy to use. As someone who uses lists a lot, I wanted my app to be a one stop place to jot down ideas and organize thoughts, rather than being a full blown task management tool. I found that the finished product satisfied these goals and tested better with my peers.

## Stretch Goals
I was not able to finish in time to add these additions. I was barely able to start working on JSON saving / loading as well, as this project ended up being much more demanding than I anticipated. Over the 50 or so hours I put into this project, the toughest parts were making the application be able to handle the dynamics of the app. Being able to handle any action, in any order, and catching any possible bugs and edge cases and fixing them in ways that did not compromise the dynamic nature of the rest of the project. JSON saving / loading is something I hope to tackle over break, and maybe even get the application able to run outside of XCode and OF. 

## External Libraries
I ended up using ofxTextInputField for this project. It is rather old, and required a few quick edits on my part to make it work, but it allowed me to more easily work with text input fields to take information from the screen and work it into the project. This library can be found here https://github.com/Flightphase/ofxTextInputField. 

## Actual Timeline of Project
Once I began working I noticed that my plan was not laid out in a way that would work. While I wanted to do the entire back end before doing the front end, I ended up needing to build both the back and front end up at the same time to enable me to test and view the app as it came together. The following is a better outline of how my project progressed
* *By the end of Week 1*, experimented with openFrameworks, getting used to the flow of setup(), update(), and draw(). Set up classes and found external library.
* *By the end of Week 2*, created rough UI in which items were clickable and maneuverable.
* *By the end of Week 3*, enabled addition of items (tasks and lists).
* *By the end of Week 4*, Enabled editing, removal, and completion of tasks and lists, as well as built up UI visually. 
