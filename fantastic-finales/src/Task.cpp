//
//  Task.cpp
//  fantastic-finales
//
//  Created by Aidan Kneller on 11/20/19.
//

#include "Task.hpp"

// Creation and edit methods
void Task::AddTitle(const std::string &title_string) {
    title  = title_string;
}

void Task::AddNotes(const std::string &notes_string) {
    notes = notes_string;
    has_notes = true;
}

void Task::GenerateCreationDate() {
    creation_date.push_back(ofGetMonth());
    creation_date.push_back(ofGetDay());
    creation_date.push_back(ofGetYear());
}

void Task::SetDueDate(int month, int day, int year) {
    due_date[0] = month;
    due_date[1] = day;
    due_date[2] = year;
    
    has_due_date = true;
}

void Task::DeleteNotes() {
    notes = "";
    has_notes = false;
}

void Task::DeleteDueDate() {
    due_date = std::vector<int>(3, 0);
    has_due_date = false;
}

std::string Task::GetTitle() {
    return title;
}

std::string Task::GetNotes() {
    return notes;
}

std::vector<int> Task::GetCreationDate() {
    return creation_date;
}

bool Task::HasDueDate() {
    return has_due_date;
}

bool Task::HasNotes() {
    return has_notes;
}

int Task::GetDueMonth() {
    return due_date[0];
}

int Task::GetDueDay() {
    return due_date[1];
}

int Task::GetDueYear() {
    return due_date[2];
}

std::vector<int> Task::GetDueDate() {
    return due_date;
}
