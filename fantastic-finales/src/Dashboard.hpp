//
//  Dashboard.hpp
//  fantastic-finales
//
//  Created by Aidan Kneller on 11/25/19.
//

#ifndef Dashboard_hpp
#define Dashboard_hpp

#include <stdio.h>
#include "inclusions.h"
#include "List.hpp"
#include "Button.hpp"
#include "ofMain.h"
#include "ofxTextInputField.h"

class Dashboard {
private:
    
    //std::vector<List> lists;
    bool has_lists = false;
    int list_to_display_index;
    int task_to_display_index;
    ViewMode view;
    std::vector<Button> list_buttons;
    std::vector<Button> task_edit_buttons;
    DataToEdit editing;
    Button new_list_button;
    Button new_task_button;
    Button settings;
    Button task_back_to_list;
    Button load_lists_button;
    Button start_new_button;
    Button settings_back_to_lists;
    Button view_completed_tasks;
    Button back_to_lists_button;
    
    int index_to_remove; // for list removal
    std::vector<int> completed_task_index;
    // holds the index of what is about to removed, and which task needs to be checked off
    // vector so that it can hold one element or be cleared to have none
    
    
    // Numbers for formatting, defined here for simple alterations
    int middle_x = ofGetWidth() / 2;
    int middle_y = ofGetHeight() / 2;
    int x_margin = 15;
    int inner_x_header_margin = 230; // Allows for header to be moved separately from tasks
    int inner_x_margin = 230;
    int header_y = 50;
    int pixels_between_objects = 50;
    int last_list_y;
    int task_title_vertical_offset = 2;
    int vertical_offset = 3; // for better alligning input field and info drawn
    int horizontal_offset = 3;
    int notes_horizontal_offset = 8;
    int width_of_prefix; // used for drawing buttons on fields, not prompts
    int list_task_divider_x = 190;
    int list_task_divider_y = 30;
    int image_bottom_buffer = 15;
    
    // Font sizing
    int helvetica_size_header = 20;
    int helvetica_size = 15;
    int helvetica_back_size = 12.5;
    
    // For drawing task information
    int task_title_y = header_y + pixels_between_objects;
    int creation_date_y = task_title_y + pixels_between_objects;
    int notes_y = creation_date_y + pixels_between_objects;
    
    
    // For keeping track of when things are entered / altered / need updated
    bool new_list_entered = false;
    bool new_task_entered = false;
    bool new_task_title = false;
    bool new_task_notes = false;
    bool task_completed = false;
    
    // Font objects
    ofTrueTypeFont helvetica_header;
    ofTrueTypeFont helvetica;
    ofTrueTypeFont helvetica_back;
    
    // Screen divider
    ofPolyline list_task_divider;
    
    // Input Field objects for adding lists and tasks
    ofxTextInputField list_title_input;
    ofxTextInputField quick_task_title_input;
    
    // Input Field objects for editing task information
    ofxTextInputField task_title_edit;
    ofxTextInputField task_notes_edit;
    
    ofImage unchecked;
    ofImage checked;
    ofImage settings_image;
    ofImage view_completed;
    
    ofColor blue = ofColor(38, 91, 114);
    ofColor dark_blue = ofColor(0, 33, 45);
    ofColor white = ofColor(255, 255, 255);
    
public:
    std::vector<List> lists; // Public so that data can be entered in within code for testing
    
    void Clear(); // clears all data from dashboard object
    void AddList(const List &list);
    void DeleteList(const int &index);
    void setup(); // loads fonts, sets buttons that will never move, and makes buttons if there is info already
    std::string ShortenTitle(const std::string &title);
    
    // Draw Information
    void DrawLists();
    void DrawCompletedTasks();
    void DrawSettingsWindow();
    void DrawTask();
    void DrawTaskTitle();
    void DrawTaskCreationDate();
    void DrawTaskNotes();
    void DrawOtherTaskInfo(); // for drawing info that is not being edited
    
    // Generate Buttons
    void MakeListButtons();
    void MakeTaskButtons();
    void MakeCheckBoxes();
    void MakeTaskEditButtons();
    
    // Draw Buttons
    void DrawNewListButton();
    void DrawNewTaskButton();
    void DrawCreateNewList();
    void DrawCreateNewTask();
    void DrawSettingsButton();
    void DrawSeeCompleteTasksButton();
    void DrawTaskBackButton();
    
    // Check for button clicks of various types
    // Split into multiple methods due to different sets of buttons and different values to return given different criteria
    void CheckListClicks(int x, int y, int button);
    void CheckTaskClicks(int x, int y, int button);
    void CheckNewListClick(int x, int y, int button);
    void CheckNewTaskClick(int x, int y, int button);
    void CheckBackToList(int x, int y, int button);
    void CheckSettingsClick(int x, int y, int button);
    void CheckLoadListsClick(int x, int y, int button);
    void CheckStartFromNewClick(int x, int y, int button);
    void CheckSettingsBackClick(int x, int y, int button);
    void CheckCompleteTaskClick(int x, int y, int button);
    void CheckCompleteTaskRelease(int x, int y, int button);
    void CheckSeeCompleteTasksClick(int x, int y, int button);
    void CheckCompletedBackToListClick(int x, int y, int button);
    void CheckTaskEditClicks(int x, int y, int button);
    
    // Setup & Update Methods
    void SetListToDisplay(const int &index);
    void SetTaskToDisplay(const int &index);
    void SetupCreateNewListField();
    void SetupCreateNewTaskField();
    void SetupTaskTitleEditField();
    void SetupTaskNotesEditField();
    void UpdateTaskInfo();
    void CreateNewList();
    void CreateNewTask();
    void DisplayNewestList();
    
    // Data Member Setters
    void SetListWasEntered(bool truth_value);
    void SetTaskWasEntered(bool truth_value);
    void SetTaskTitleEntered(bool truth_value);
    void SetTaskNotesEntered(bool truth_value);
    void SetTaskCompleted(bool truth_value);
    
    // Data Member Getters
    bool ListWasEntered();
    bool TaskWasEntered();
    bool TaskTitleEntered();
    bool TaskNotesEntered();
    bool TaskCompleted();
    ViewMode GetViewMode();
    int GetDividerX();
    DataToEdit GetDataMemberToEdit();
    
    // Draw text field objects
    void DrawTaskTitleEdit();
    void DrawTaskNotesEdit();
};


#endif /* Dashboard_hpp */
