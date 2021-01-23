//
//  Button.hpp
//  fantastic-finales
//
//  Created by Aidan Kneller on 11/30/19.
//

#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>
#include "ofMain.h"
#include "inclusions.h"
#include "Task.hpp"

class Button {
private:
    std::vector<int> coordinates = std::vector<int>(4, 0);
    
    // Data member that a task editing button may link to [optional]
    DataToEdit data;
    
public:
    // Every button will have these
    void SetCoordinates(int x, int y, int width, int height);
    std::vector<int> GetCoordinates();
    void Reset();
    
    // Enables linking of buttons for use of task editing
    void SetDataToEdit(const DataToEdit &data_member);
    DataToEdit GetDataToEdit();
};

#endif /* Button_hpp */
