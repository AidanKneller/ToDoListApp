//
//  Button.cpp
//  fantastic-finales
//
//  Created by Aidan Kneller on 11/30/19.
//

#include "Button.hpp"

void Button::SetCoordinates(int x, int y, int width, int height) {
    coordinates[0] = x; // bottom left coordinate
    coordinates[1] = y; // bottom left coordinate
    coordinates[2] = width;
    coordinates[3] = height;
}

std::vector<int> Button::GetCoordinates() {
    return coordinates;
}

void Button::Reset() {
    coordinates = std::vector<int>(4, 0);
}

void Button::SetDataToEdit(const DataToEdit &data_member) {
    data = data_member;
}

DataToEdit Button::GetDataToEdit() {
    return data;
}
