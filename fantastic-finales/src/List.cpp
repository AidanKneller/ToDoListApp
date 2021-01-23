//
//  List.cpp
//  fantastic-finales
//
//  Created by Aidan Kneller on 11/20/19.
//

#include "List.hpp"

void List::AddTask(const Task &task) {
    if (!has_tasks) {
        tasks.push_back(task);
        has_tasks = true;
    } else {
        tasks.push_back(task);
    }
}

void List::EditTitle(const std::string &new_title) {
    title = new_title;
}

std::string List::GetTitle() {
    return title;
}

std::vector<Task> List::GetTasks() {
    return tasks;
}

std::vector<Button> List::GetTaskButtons() {
    return task_buttons;
}

void List::AddTaskButton(const Button &task_button) {
    task_buttons.push_back(task_button);
}

void List::ClearTaskButtons() {
    task_buttons.clear();
}

bool List::HasTasks() {
    return has_tasks;
}

void List::SetHasTasks(bool truth_value) {
    has_tasks = truth_value;
}

void List::SetLastTaskY(int y) {
    last_task_y = y;
}

int List::GetLastTaskY() {
    return last_task_y;
}

std::vector<Task> List::GetCompleted() {
    return completed_tasks;
}

void List::AddToCompleted(const int &index) {
    Task task = tasks[index];
    completed_tasks.push_back(task);
    tasks.erase(tasks.begin()+index);
}

void List::AddCheckBox(const Button &check_box) {
    check_boxes.push_back(check_box);
}

void List::ClearCheckBoxes() {
    check_boxes.clear();
}

std::vector<Button> List::GetCheckBoxes() {
    return check_boxes;
}
