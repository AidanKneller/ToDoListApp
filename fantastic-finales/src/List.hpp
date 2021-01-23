//
//  List.hpp
//  fantastic-finales
//
//  Created by Aidan Kneller on 11/20/19.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include "inclusions.h"
#include "Task.hpp"
#include "Button.hpp"
#include "ofTrueTypeFont.h"
#include "ofxTextInputField.h"

class List {
    
private:
    std::string title;
    //std::vector<Task> tasks;
    std::vector<Button> task_buttons;
    std::vector<Button> check_boxes;
    bool has_tasks = false;
    int last_task_y;
    std::vector<Task> completed_tasks;
    
public:
    std::vector<Task> tasks; // Needs to be public so I can access and change it as we move, so that data can be saved correctly
    void Clear();
    void AddTask(const Task &task);
    void DeleteTask();
    void EditTitle(const std::string &new_title);
    std::string GetTitle();
    std::vector<Task> GetTasks();
    std::vector<Button> GetTaskButtons();
    void AddTaskButton(const Button &task_button);
    void ClearTaskButtons();
    void AddCheckBox(const Button &check_box);
    void ClearCheckBoxes();
    std::vector<Button> GetCheckBoxes();
    bool HasTasks();
    void SetLastTaskY(int y);
    int GetLastTaskY();
    std::vector<Task> GetCompleted();
    void AddToCompleted(const int &index);
    void SetHasTasks(bool truth_value);
};


#endif /* List_hpp */
