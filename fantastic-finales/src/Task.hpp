//
//  Task.hpp
//  fantastic-finales
//
//  Created by Aidan Kneller on 11/20/19.
//

#ifndef Task_hpp
#define Task_hpp

#include <stdio.h>
#include "inclusions.h"
#include "ofMain.h"

class Task {
    
private:
    std::string title;
    std::string notes;
    std::vector<int> creation_date;
    std::vector<int> due_date = std::vector<int>(3, 0);
    bool has_due_date = false;
    bool has_notes = false;
    
public:
    
    void AddTitle(const std::string &title_string);
    void AddNotes(const std::string &notes_string);
    void GenerateCreationDate();
    void SetDueDate(int month, int day, int year);
    void DeleteNotes();
    void DeleteDueDate();
    bool HasDueDate();
    bool HasNotes();
    std::string GetTitle();
    std::string GetNotes();
    std::vector<int> GetCreationDate();
    std::vector<int> GetDueDate();
    int GetDueMonth();
    int GetDueDay();
    int GetDueYear();
};


#endif /* Task_hpp */
