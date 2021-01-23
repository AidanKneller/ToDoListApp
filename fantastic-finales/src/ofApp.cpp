#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    List l1;
    l1.EditTitle("Grocery");
    dash.AddList(l1);
    
    Task t1;
    t1.AddTitle("Go to the store");
    t1.GenerateCreationDate();
    t1.AddNotes("Make sure to get batteries");
    dash.lists[0].AddTask(t1);
    
    dash.setup(); // Loads the fonts, determines if there are lists, and makes buttons for any loaded lists and buttons
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (dash.ListWasEntered()) {
        dash.CreateNewList();
        dash.MakeListButtons(); // refreshes the vector of list buttons upon each addition
        dash.SetupCreateNewListField(); // resets input field for next use
        dash.SetListWasEntered(false);
        dash.DisplayNewestList();
    } else if (dash.TaskWasEntered()) {
        dash.CreateNewTask();
        dash.MakeTaskButtons();
        dash.MakeCheckBoxes();
        dash.SetupCreateNewTaskField();
        dash.SetTaskWasEntered(false);
    } else if (dash.TaskTitleEntered()) {
        dash.UpdateTaskInfo();
        dash.SetupTaskTitleEditField();
        dash.SetTaskTitleEntered(false);
    } else if (dash.TaskNotesEntered()) {
        dash.UpdateTaskInfo();
        dash.SetupTaskNotesEditField();
        dash.SetTaskNotesEntered(false);
    } else if (dash.TaskCompleted()) {
        dash.MakeTaskButtons();
        dash.MakeCheckBoxes();
        dash.SetTaskCompleted(false);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (dash.GetViewMode() == LIST) {
        dash.DrawLists();
        dash.DrawNewListButton();
        dash.DrawNewTaskButton();
        dash.DrawSettingsButton();
        dash.DrawSeeCompleteTasksButton();
    } else if (dash.GetViewMode() == TASK) {
        dash.DrawTask();
    } else if (dash.GetViewMode() == NEW_LIST) {
        dash.DrawLists();
        dash.SetupCreateNewListField();
        dash.DrawCreateNewList();
    } else if (dash.GetViewMode() == NEW_TASK) {
        dash.DrawLists();
        dash.SetupCreateNewTaskField();
        dash.DrawCreateNewTask();
    } else if (dash.GetViewMode() == EDIT_TASK) {
        switch(dash.GetDataMemberToEdit()) {
            case TITLE:
                dash.SetupTaskTitleEditField();
                dash.DrawTaskTitleEdit();
                dash.DrawOtherTaskInfo();
                break;
            case NOTES:
                dash.SetupTaskNotesEditField();
                dash.DrawTaskNotesEdit();
                dash.DrawOtherTaskInfo();
                break;
        }
    } else if (dash.GetViewMode() == SETTINGS) {
        dash.DrawSettingsWindow();
    } else if (dash.GetViewMode() == VIEW_COMPLETED) {
        dash.DrawCompletedTasks();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_RETURN) {
        if (dash.GetViewMode() == NEW_LIST) {
            dash.SetListWasEntered(true);
        } else if (dash.GetViewMode() == NEW_TASK) {
            dash.SetTaskWasEntered(true);
        } else if (dash.GetViewMode() == EDIT_TASK) {
            switch(dash.GetDataMemberToEdit()) {
                case TITLE:
                    dash.SetTaskTitleEntered(true);
                    break;
                case NOTES:
                    dash.SetTaskNotesEntered(true);
                    break;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    // If the mode is currently List, then either lists or buttons can be selected
    if (dash.GetViewMode() == LIST) {
        // if its to the left of 175, it is a list. If it is to the right, it is a task
        if (x < dash.GetDividerX()) {
            dash.CheckListClicks(x, y, button);
            dash.CheckNewListClick(x, y, button);
            dash.CheckSettingsClick(x, y, button);
        } else if (x > dash.GetDividerX()) {
            dash.CheckTaskClicks(x, y, button);
            dash.CheckNewTaskClick(x, y, button);
            dash.CheckCompleteTaskClick(x, y, button);
            dash.CheckSeeCompleteTasksClick(x, y, button);
        }
    } else if (dash.GetViewMode() == TASK) {
        // If the mode is Task, it is either Edit, Delete, or back to the list
        dash.CheckBackToList(x, y, button);
        dash.MakeTaskEditButtons();
        dash.CheckTaskEditClicks(x, y, button);
    } else if (dash.GetViewMode() == SETTINGS) {
        dash.CheckLoadListsClick(x, y, button);
        dash.CheckStartFromNewClick(x, y, button);
        dash.CheckSettingsBackClick(x, y, button);
    } else if (dash.GetViewMode() == VIEW_COMPLETED) {
        dash.CheckCompletedBackToListClick(x, y, button);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    dash.CheckCompleteTaskRelease(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
