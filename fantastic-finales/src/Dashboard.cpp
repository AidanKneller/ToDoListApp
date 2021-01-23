//
//  Dashboard.cpp
//  fantastic-finales
//
//  Created by Aidan Kneller on 11/25/19.
//

#include "Dashboard.hpp"

void Dashboard::Clear() {
    lists.clear();
    list_buttons.clear();
    has_lists = false;
}

void Dashboard::AddList(const List &list) {
    if (!has_lists) {
        lists.push_back(list);
        has_lists = true;
    } else {
        lists.push_back(list);
    }
}

void Dashboard::DeleteList(const int &index) {
    lists.erase(lists.begin()+index);
}

void Dashboard::setup() {
    ofBackground(255, 255, 255);
    
    // Load fonts
    helvetica_header.load("helvetica-bold.ttf", helvetica_size_header);
    helvetica.load("helvetica-bold.ttf", helvetica_size);
    helvetica_back.load("helvetica-bold.ttf", helvetica_back_size);
    
    // Load images
    unchecked.load("blank.png");
    checked.load("check.png");
    settings_image.load("settings.png");
    view_completed.load("view.png");
    
    // resize images
    unchecked.resize(unchecked.getWidth() / 10, unchecked.getHeight() / 10);
    checked.resize(checked.getWidth() / 10, checked.getHeight() / 10);
    settings_image.resize(settings_image.getWidth() / 4, settings_image.getHeight() / 4);
    view_completed.resize(view_completed.getWidth() / 4.25, view_completed.getHeight() / 4.25);
    
    // Determine if there has been any loaded information
    if (lists.size() != 0) {
        has_lists = true;
        list_to_display_index = 0;
        MakeListButtons();
        MakeTaskButtons();
        MakeCheckBoxes();
    }
    
    // Sets default view
    view = LIST;
    
    // Make divider lines
    list_task_divider.addVertex(list_task_divider_x, list_task_divider_y);
    list_task_divider.addVertex(list_task_divider_x, ofGetHeight());
    
    // THESE BUTTONS WILL NEVER NEED TO MOVE THROUGHOUT THE APP RUNNING
    // set the bounds for the settings button
    settings.SetCoordinates(list_task_divider_x / 2 - settings_image.getWidth() / 2, ofGetHeight() - image_bottom_buffer, list_task_divider_x / 2 - settings_image.getWidth() / 2 + settings_image.getWidth(), settings_image.getHeight());
    
    // Buttons within settings window
    load_lists_button.SetCoordinates(middle_x - (helvetica_header.stringWidth("Load Lists") / 2), middle_y - pixels_between_objects, middle_x - (helvetica_header.stringWidth("Load Lists") / 2) + helvetica_header.stringWidth("Load Lists"), helvetica_header.getLineHeight());
    start_new_button.SetCoordinates(middle_x - (helvetica_header.stringWidth("Start from New") /2), middle_y, middle_x - (helvetica_header.stringWidth("Start from New") / 2) + helvetica_header.stringWidth("Start from New"), helvetica_header.getLineHeight());
    settings_back_to_lists.SetCoordinates(middle_x - (helvetica_header.stringWidth("Back") /2), middle_y + pixels_between_objects, middle_x - (helvetica_header.stringWidth("Back") / 2) + helvetica_header.stringWidth("Back"), helvetica_header.getLineHeight());
    
    // set the view completed tasks button
    view_completed_tasks.SetCoordinates(ofGetWidth() - x_margin - view_completed.getWidth(), ofGetHeight() - image_bottom_buffer, ofGetWidth() - x_margin, view_completed.getHeight());
}

std::string Dashboard::ShortenTitle(const std::string &title) {
    std::string shortened_string = title;
    bool short_enough = false;
    while (!short_enough) {
        shortened_string.pop_back();
        if (x_margin + helvetica.stringWidth(shortened_string) + helvetica.stringWidth("...") < list_task_divider_x - 10) {
            short_enough = true;
        }
    }
    
    // If last character is a space, remove it too so the "..." is not hanging
    if (shortened_string.back() == ' ') {
        shortened_string.pop_back();
    }
    
    shortened_string += "...";
    return shortened_string;
}

void Dashboard::DrawLists() {
    int y_coor = header_y;
    
    ofSetColor(blue);
    helvetica_header.drawString("Lists", x_margin, y_coor);
    list_task_divider.draw();
    ofSetColor(white);
    
    // If not in deletion mode, do as normal
    if (GetViewMode() != DELETE_LIST) {
        // show lists
        if (has_lists) {
            
            // Draw the lists
            for (int i = 0; i < lists.size(); i++) {
                y_coor += pixels_between_objects;
                std::string title = lists[i].GetTitle();
                ofSetColor(dark_blue);
                if (x_margin + helvetica.stringWidth(title) > list_task_divider_x) {
                    helvetica.drawString(ShortenTitle(title), x_margin, y_coor);
                } else {
                    helvetica.drawString(title, x_margin, y_coor);
                }
                ofSetColor(white);
            }
            
            // record the y coordinate of the last list
            last_list_y = y_coor;
            
            // Draw the tasks and the check boxes
            y_coor = header_y;
            if (lists[list_to_display_index].HasTasks()) {
                ofSetColor(blue);
                helvetica_header.drawString(lists[list_to_display_index].GetTitle(), inner_x_header_margin, y_coor);
                ofSetColor(white);
                for (int i = 0; i < lists[list_to_display_index].GetTasks().size(); i++) {
                    Task task = lists[list_to_display_index].GetTasks()[i];
                    std::string title = task.GetTitle();
                    y_coor += pixels_between_objects;
                    ofSetColor(dark_blue);
                    helvetica.drawString(title, inner_x_margin, y_coor);
                    ofSetColor(white);
                    // the stand in check box
                    if (completed_task_index.size() == 1) {
                        if (i == completed_task_index[0]) {
                            checked.draw(list_task_divider_x, y_coor - 30);
                            
                        }
                    } else {
                        unchecked.draw(list_task_divider_x, y_coor - 30);
                    }
                }
                
                // record the y coordinate of the last task within the list at hand
                lists[list_to_display_index].SetLastTaskY(y_coor);
                
            } else {
                lists[list_to_display_index].SetLastTaskY(y_coor); // Save it regardless since the zeroeth task is technically the last one
                ofSetColor(blue);
                helvetica_header.drawString(lists[list_to_display_index].GetTitle(), inner_x_margin, y_coor);
                ofSetColor(white);
            }
            
        } else {
            ofSetColor(dark_blue);
            last_list_y = y_coor; // Save regardless because the zeroeth list is the last one
            helvetica.drawString("No Lists", ofGetWidth()/2, ofGetHeight()/2);
            ofSetColor(white);
        }
    } else { // If in deletion mode, only draw the list names
        for (int i = 0; i < lists.size(); i++) {
            ofSetColor(dark_blue);
            y_coor += pixels_between_objects;
            helvetica.drawString(lists[i].GetTitle(), x_margin, y_coor);
            ofSetColor(white);
        }
    }
}

void Dashboard::DrawCompletedTasks() {
    ofSetColor(dark_blue);
    int y_coor = header_y;
    int string_width = helvetica.stringWidth("Back to ") + helvetica.stringWidth(lists[list_to_display_index].GetTitle());
    helvetica_back.drawString("Back to " + lists[list_to_display_index].GetTitle(), x_margin, y_coor);
    back_to_lists_button.SetCoordinates(x_margin, y_coor, string_width, helvetica_back.getLineHeight());
    ofSetColor(blue);
    y_coor += pixels_between_objects;
    helvetica_header.drawString(lists[list_to_display_index].GetTitle() + " -- Completed Tasks", x_margin, y_coor);
    ofSetColor(dark_blue);
    if (lists[list_to_display_index].GetCompleted().size() == 0) {
        helvetica.drawString("No Completed Tasks", middle_x - (helvetica.stringWidth("No Completed Tasks") / 2), middle_y);
    } else {
        for (Task task : lists[list_to_display_index].GetCompleted()) {
            y_coor += pixels_between_objects;
            helvetica.drawString(task.GetTitle(), x_margin, y_coor);
        }
    }
    ofSetColor(white);
}

void Dashboard::DrawSettingsWindow() {
    ofSetColor(blue);
    helvetica_header.drawString("Load Lists", middle_x - (helvetica_header.stringWidth("Load Lists") / 2), middle_y - pixels_between_objects);
    helvetica_header.drawString("Start from New", middle_x - (helvetica_header.stringWidth("Start from New") / 2), middle_y);
    helvetica_header.drawString("Back", middle_x - (helvetica_header.stringWidth("Back") / 2), middle_y + pixels_between_objects);
    ofSetColor(white);
}

void Dashboard::DrawTask() {
    DrawTaskBackButton();
    DrawTaskTitle();
    DrawTaskCreationDate();
    DrawTaskNotes();
}

void Dashboard::DrawTaskTitle() {
    ofSetColor(blue);
    std::string title = lists[list_to_display_index].tasks[task_to_display_index].GetTitle();
    helvetica_header.drawString(title, x_margin, task_title_y);
    ofSetColor(white);
}

void Dashboard::DrawTaskCreationDate() {
    ofSetColor(dark_blue);
    std::string creation_date;
    for (int i = 0; i < 3; i++) {
        if (i < 2) {
            creation_date += std::to_string(lists[list_to_display_index].tasks[task_to_display_index].GetCreationDate()[i]) + "/";
        } else {
            creation_date += std::to_string(lists[list_to_display_index].tasks[task_to_display_index].GetCreationDate()[i]);
        }
    }
    helvetica.drawString("Created on " + creation_date, x_margin, creation_date_y);
    ofSetColor(white);
}

void Dashboard::DrawTaskNotes() {
    ofSetColor(dark_blue);
    if (lists[list_to_display_index].tasks[task_to_display_index].HasNotes()) {
        helvetica.drawString("Notes: " + lists[list_to_display_index].tasks[task_to_display_index].GetNotes(), x_margin, notes_y);
    } else {
        helvetica.drawString("Notes: Click here to add task notes", x_margin, notes_y);
    }
    ofSetColor(white);
}

void Dashboard::DrawOtherTaskInfo() {
    switch (GetDataMemberToEdit()) {
        case TITLE:
            DrawTaskBackButton();
            DrawTaskCreationDate();
            DrawTaskNotes();
            break;
        case NOTES:
            DrawTaskBackButton();
            DrawTaskTitle();
            DrawTaskCreationDate();
            ofSetColor(dark_blue);
            helvetica.drawString("Notes:", x_margin, notes_y); // only draw the notes prompt
            ofSetColor(white);
            break;                                             // since notes are being edited
    }
}

void Dashboard::MakeListButtons() {
    list_buttons.clear();
    
    int y_coor = header_y;
    for (List list : lists) {
        y_coor += pixels_between_objects;
        Button list_button;
        list_button.SetCoordinates(x_margin, y_coor, list_task_divider_x, helvetica.getLineHeight());
        list_buttons.push_back(list_button);
    }
}

void Dashboard::MakeTaskButtons() {
    if (has_lists && lists[list_to_display_index].HasTasks()) {
        lists[list_to_display_index].ClearTaskButtons();
        
        int y_coor = header_y;
        for (Task task : lists[list_to_display_index].GetTasks()) {
            y_coor += pixels_between_objects;
            Button task_button;
            task_button.SetCoordinates(inner_x_margin, y_coor, ofGetWidth(), helvetica.getLineHeight());
            lists[list_to_display_index].AddTaskButton(task_button);
        }
    }
}

void Dashboard::MakeCheckBoxes() {
    if (has_lists && lists[list_to_display_index].HasTasks()) {
        lists[list_to_display_index].ClearCheckBoxes();
        
        int y_coor = header_y;
        for (Task task : lists[list_to_display_index].GetTasks()) {
            y_coor += pixels_between_objects;
            Button check_box;
            check_box.SetCoordinates(list_task_divider_x + 10, y_coor, list_task_divider_x + 30, 20);
            lists[list_to_display_index].AddCheckBox(check_box);
        }
    }
}

void Dashboard::MakeTaskEditButtons() {
    task_edit_buttons.clear();
    
    int y_coor = header_y + pixels_between_objects;
    
    Button title_edit_button;
    title_edit_button.SetDataToEdit(TITLE);
    title_edit_button.SetCoordinates(x_margin, y_coor, helvetica_header.stringWidth(lists[list_to_display_index].tasks[task_to_display_index].GetTitle()), helvetica_header.getLineHeight());
    task_edit_buttons.push_back(title_edit_button);
    
    y_coor += (pixels_between_objects * 2);
    
    Button notes_edit_button;
    notes_edit_button.SetDataToEdit(NOTES);
    std::string notes;
    if (lists[list_to_display_index].tasks[task_to_display_index].HasNotes()) {
        notes = lists[list_to_display_index].tasks[task_to_display_index].GetNotes();
    } else {
        notes = "Click here to add task notes";
    }
    width_of_prefix = helvetica.stringWidth("Notes: ");
    notes_edit_button.SetCoordinates(x_margin + width_of_prefix, y_coor, x_margin + width_of_prefix+ helvetica.stringWidth(notes), helvetica.getLineHeight());
    task_edit_buttons.push_back(notes_edit_button);
}

void Dashboard::DrawNewListButton() {
    ofSetColor(blue);
    new_list_button.Reset();
    new_list_button.SetCoordinates(x_margin, last_list_y + pixels_between_objects, list_task_divider_x, helvetica.getLineHeight());
    helvetica.drawString("Add New List...", x_margin, last_list_y + pixels_between_objects);
    ofSetColor(white);
}

void Dashboard::DrawNewTaskButton() {
    ofSetColor(blue);
    if (has_lists) {
        int last_task_y = lists[list_to_display_index].GetLastTaskY();
        std::string prompt = "Add New Task...";
        new_task_button.Reset();
        new_task_button.SetCoordinates(inner_x_margin, last_task_y + pixels_between_objects, inner_x_margin + helvetica.stringWidth(prompt), helvetica.getLineHeight());
        helvetica.drawString(prompt, inner_x_margin, last_task_y + pixels_between_objects);
    }
}

void Dashboard::DrawCreateNewList() {
    ofSetColor(dark_blue);
    list_title_input.beginEditing();
    list_title_input.draw();
    ofSetColor(white);
}

void Dashboard::DrawCreateNewTask() {
    ofSetColor(dark_blue);
    quick_task_title_input.beginEditing();
    quick_task_title_input.draw();
    ofSetColor(white);
}

void Dashboard::DrawSettingsButton() {
    ofSetColor(white);
    settings_image.draw(list_task_divider_x / 2 - settings_image.getWidth() / 2, ofGetHeight() - image_bottom_buffer - settings_image.getHeight());
}

void Dashboard::DrawSeeCompleteTasksButton() {
    view_completed.draw(ofGetWidth() - view_completed.getWidth() - x_margin, ofGetHeight() - image_bottom_buffer - view_completed.getHeight());
}

void Dashboard::DrawTaskBackButton() {
    ofSetColor(dark_blue);
    int string_width = helvetica.stringWidth("Back to ") + helvetica.stringWidth(lists[list_to_display_index].GetTitle());
    helvetica_back.drawString("Back to " + lists[list_to_display_index].GetTitle(), x_margin, header_y);
    task_back_to_list.SetCoordinates(x_margin, header_y, string_width, helvetica_back.getLineHeight());
    ofSetColor(white);
}

void Dashboard::CheckListClicks(int x, int y, int button) {
    if (button == 0) {
        for (int i = 0; i < list_buttons.size(); i++) {
            int x_start = list_buttons[i].GetCoordinates()[0]; // left limit
            int y_start = list_buttons[i].GetCoordinates()[3] - list_buttons[i].GetCoordinates()[1]; // top limit
            int x_end = list_buttons[i].GetCoordinates()[2]; // right limit
            int y_end = list_buttons[i].GetCoordinates()[1]; // bottom limit
            if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
                SetListToDisplay(i);
                break;
            }
        }
    }
}

void Dashboard::CheckTaskClicks(int x, int y, int button) {
    if (button == 0) {
        for (int i = 0; i < lists[list_to_display_index].GetTaskButtons().size(); i++) {
            int x_start = lists[list_to_display_index].GetTaskButtons()[i].GetCoordinates()[0]; // left limit
            int y_start = lists[list_to_display_index].GetTaskButtons()[i].GetCoordinates()[1] - lists[list_to_display_index].GetTaskButtons()[i].GetCoordinates()[3]; // top limit
            int x_end = lists[list_to_display_index].GetTaskButtons()[i].GetCoordinates()[2]; // right limit
            int y_end = lists[list_to_display_index].GetTaskButtons()[i].GetCoordinates()[1]; // bottom limit
            if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
                SetTaskToDisplay(i);
                break;
            }
        }
    }
}

void Dashboard::CheckNewListClick(int x, int y, int button) {
    if (button == 0) {
        int x_start = new_list_button.GetCoordinates()[0];
        int y_start = new_list_button.GetCoordinates()[1] - new_list_button.GetCoordinates()[3];
        int x_end = new_list_button.GetCoordinates()[2];
        int y_end = new_list_button.GetCoordinates()[1];
        if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
            view = NEW_LIST;
        }
    }
}

void Dashboard::CheckNewTaskClick(int x, int y, int button) {
    if (button == 0) {
        int x_start = new_task_button.GetCoordinates()[0];
        int y_start = new_task_button.GetCoordinates()[1] - new_task_button.GetCoordinates()[3];
        int x_end = new_task_button.GetCoordinates()[2];
        int y_end = new_task_button.GetCoordinates()[1];
        if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
            view = NEW_TASK;
        }
    }
}

void Dashboard::CheckBackToList(int x, int y, int button) {
    if (button == 0) {
        int x_start = task_back_to_list.GetCoordinates()[0]; // left limit
        int y_start = task_back_to_list.GetCoordinates()[1] - task_back_to_list.GetCoordinates()[3]; // top limit
        int x_end = task_back_to_list.GetCoordinates()[2]; // right limit
        int y_end = task_back_to_list.GetCoordinates()[1]; // bottom limit
        if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
            view = LIST;
        }
    }
}

void Dashboard::CheckSettingsClick(int x, int y, int button) {
    if (button == 0) {
        int x_start = settings.GetCoordinates()[0];
        int y_start = settings.GetCoordinates()[1] - settings.GetCoordinates()[3];
        int x_end = settings.GetCoordinates()[2];
        int y_end = settings.GetCoordinates()[1];
        if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
            view = SETTINGS;
        }
    }
}

void Dashboard::CheckLoadListsClick(int x, int y, int button) {
    if (button == 0) {
        int x_start = load_lists_button.GetCoordinates()[0];
        int y_start = load_lists_button.GetCoordinates()[1] - load_lists_button.GetCoordinates()[3];
        int x_end = load_lists_button.GetCoordinates()[2];
        int y_end = load_lists_button.GetCoordinates()[1];
        if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
            view = LIST;
        }
    }
}

void Dashboard::CheckStartFromNewClick(int x, int y, int button) {
    if (button == 0) {
        int x_start = start_new_button.GetCoordinates()[0];
        int y_start = start_new_button.GetCoordinates()[1] - start_new_button.GetCoordinates()[3]; // top limit
        int x_end = start_new_button.GetCoordinates()[2];
        int y_end = start_new_button.GetCoordinates()[1];
        if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
            view = LIST;
            Clear();
            setup();
        }
    }
}

void Dashboard::CheckSettingsBackClick(int x, int y, int button) {
    if (button == 0) {
        int x_start = settings_back_to_lists.GetCoordinates()[0];
        int y_start = settings_back_to_lists.GetCoordinates()[1] - settings_back_to_lists.GetCoordinates()[3];
        int x_end = settings_back_to_lists.GetCoordinates()[2];
        int y_end = settings_back_to_lists.GetCoordinates()[1];
        if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
            view = LIST;
        }
    }
}

void Dashboard::CheckCompleteTaskClick(int x, int y, int button) {
    if (button == 0) {
        for (int i = 0; i < lists[list_to_display_index].GetCheckBoxes().size(); i++) {
            int x_start = lists[list_to_display_index].GetCheckBoxes()[i].GetCoordinates()[0];
            int y_start = lists[list_to_display_index].GetCheckBoxes()[i].GetCoordinates()[1] - lists[list_to_display_index].GetCheckBoxes()[i].GetCoordinates()[3];
            int x_end = lists[list_to_display_index].GetCheckBoxes()[i].GetCoordinates()[2];
            int y_end = lists[list_to_display_index].GetCheckBoxes()[i].GetCoordinates()[1];
            if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
                completed_task_index.push_back(i);
                break;
            }
        }
    }
}

void Dashboard::CheckCompleteTaskRelease(int x, int y, int button) {
    if (button == 0) {
        for (int i = 0; i < lists[list_to_display_index].GetCheckBoxes().size(); i++) {
            int x_start = lists[list_to_display_index].GetCheckBoxes()[i].GetCoordinates()[0];
            int y_start = lists[list_to_display_index].GetCheckBoxes()[i].GetCoordinates()[1] - lists[list_to_display_index].GetCheckBoxes()[i].GetCoordinates()[3];
            int x_end = lists[list_to_display_index].GetCheckBoxes()[i].GetCoordinates()[2];
            int y_end = lists[list_to_display_index].GetCheckBoxes()[i].GetCoordinates()[1];
            if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
                if (completed_task_index.size() == 1) {
                    if (i == completed_task_index[0]) {
                        task_completed = true;
                        lists[list_to_display_index].AddToCompleted(completed_task_index[0]);
                        completed_task_index.clear();
                        break;
                    }
                }
            }
        }
    }
}

void Dashboard::CheckSeeCompleteTasksClick(int x, int y, int button) {
    if (button == 0) {
        int x_start = view_completed_tasks.GetCoordinates()[0];
        int y_start = view_completed_tasks.GetCoordinates()[1] - view_completed_tasks.GetCoordinates()[3];
        int x_end = view_completed_tasks.GetCoordinates()[2];
        int y_end = view_completed_tasks.GetCoordinates()[1];
        if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
            view = VIEW_COMPLETED;
        }
    }
}

void Dashboard::CheckCompletedBackToListClick(int x, int y, int button) {
    if (button == 0) {
        int x_start = back_to_lists_button.GetCoordinates()[0];
        int y_start = back_to_lists_button.GetCoordinates()[1] - back_to_lists_button.GetCoordinates()[3];
        int x_end = back_to_lists_button.GetCoordinates()[2];
        int y_end = back_to_lists_button.GetCoordinates()[1];
        if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
            view = LIST;
        }
    }
}

void Dashboard::CheckTaskEditClicks(int x, int y, int button) {
    if (button == 0) {
        for (Button edit_button : task_edit_buttons) {
            int x_start = edit_button.GetCoordinates()[0];
            int y_start = edit_button.GetCoordinates()[1] - edit_button.GetCoordinates()[3];
            int x_end = edit_button.GetCoordinates()[2];
            int y_end = edit_button.GetCoordinates()[1];
            if (x_start <= x && x<= x_end && y_start <= y && y <= y_end) {
                view = EDIT_TASK;
                editing = edit_button.GetDataToEdit();
            }
        }
    }
}

void Dashboard::SetListToDisplay(const int &index) {
    list_to_display_index = index;
    
    if (view != LIST) {
        view = LIST;
    }
}

void Dashboard::SetTaskToDisplay(const int &index) {
    task_to_display_index = index;
    view = TASK;
}

void Dashboard::SetupCreateNewListField() {
    list_title_input.setup();
    list_title_input.setFont(helvetica);
    list_title_input.bounds.width = list_task_divider_x;
    list_title_input.bounds.height = helvetica.getLineHeight();
    list_title_input.bounds.x = x_margin - horizontal_offset;
    list_title_input.bounds.y = header_y + pixels_between_objects + (pixels_between_objects * lists.size()) - helvetica.getLineHeight() - vertical_offset;
    list_title_input.autoClear = true;
}

void Dashboard::SetupCreateNewTaskField() {
    quick_task_title_input.setup();
    quick_task_title_input.setFont(helvetica);
    quick_task_title_input.bounds.width = ofGetWidth();
    quick_task_title_input.bounds.height = helvetica.getLineHeight();
    quick_task_title_input.bounds.x = inner_x_margin - horizontal_offset;
    quick_task_title_input.bounds.y = header_y + pixels_between_objects + (pixels_between_objects * lists[list_to_display_index].GetTasks().size()) - helvetica.getLineHeight() - vertical_offset;
    quick_task_title_input.autoClear = true;
}

void Dashboard::SetupTaskTitleEditField() {
    task_title_edit.setup();
    task_title_edit.setFont(helvetica_header);
    task_title_edit.bounds.width = ofGetWidth();
    task_title_edit.bounds.height = helvetica_header.getLineHeight();
    task_title_edit.bounds.x = x_margin - horizontal_offset;
    task_title_edit.bounds.y = task_title_y - helvetica_header.getLineHeight() - task_title_vertical_offset;
    task_title_edit.autoClear = true;
}

void Dashboard::SetupTaskNotesEditField() {
    task_notes_edit.setup();
    task_notes_edit.setFont(helvetica);
    task_notes_edit.bounds.width = ofGetWidth();
    task_notes_edit.bounds.height = helvetica.getLineHeight();
    task_notes_edit.bounds.x = x_margin + helvetica.stringWidth("Notes:x") - notes_horizontal_offset;
    task_notes_edit.bounds.y = notes_y - helvetica.getLineHeight() - vertical_offset;
    task_notes_edit.autoClear = true;
}

void Dashboard::UpdateTaskInfo() {
    switch(GetDataMemberToEdit()) {
        case TITLE: {
            std::string new_title = task_title_edit.text;
            lists[list_to_display_index].tasks[task_to_display_index].AddTitle(new_title);
            break;
        }
        case NOTES: {
            std::string new_notes = task_notes_edit.text;
            lists[list_to_display_index].tasks[task_to_display_index].AddNotes(new_notes);
            break;
        }
    }
    view = TASK;
}

void Dashboard::CreateNewList() {
    List new_list;
    new_list.EditTitle(list_title_input.text);
    AddList(new_list);
    
    view = LIST;
}

void Dashboard::CreateNewTask() {
    Task new_task;
    new_task.AddTitle(quick_task_title_input.text);
    new_task.GenerateCreationDate();
    lists[list_to_display_index].AddTask(new_task);
    view = LIST;
}

void Dashboard::DisplayNewestList() {
    list_to_display_index = lists.size() - 1;
}

void Dashboard::SetListWasEntered(bool truth_value) {
    new_list_entered = truth_value;
}

void Dashboard::SetTaskWasEntered(bool truth_value) {
    new_task_entered = truth_value;
}

void Dashboard::SetTaskTitleEntered(bool truth_value) {
    new_task_title = truth_value;
}

void Dashboard::SetTaskNotesEntered(bool truth_value) {
    new_task_notes = truth_value;
}
void Dashboard::SetTaskCompleted(bool truth_value) {
    task_completed = truth_value;
}

bool Dashboard::ListWasEntered() {
    return new_list_entered;
}

bool Dashboard::TaskWasEntered() {
    return new_task_entered;
}

bool Dashboard::TaskTitleEntered() {
    return new_task_title;
}

bool Dashboard::TaskNotesEntered() {
    return new_task_notes;
}

bool Dashboard::TaskCompleted() {
    return task_completed;
}

ViewMode Dashboard::GetViewMode() {
    return view;
}

int Dashboard::GetDividerX() {
    return list_task_divider_x;
}

DataToEdit Dashboard::GetDataMemberToEdit() {
    return editing;
}

void Dashboard::DrawTaskTitleEdit() {
    ofSetColor(blue);
    task_title_edit.beginEditing();
    task_title_edit.draw();
    ofSetColor(white);
}

void Dashboard::DrawTaskNotesEdit() {
    ofSetColor(dark_blue);
    task_notes_edit.beginEditing();
    task_notes_edit.draw();
    ofSetColor(white);
}
