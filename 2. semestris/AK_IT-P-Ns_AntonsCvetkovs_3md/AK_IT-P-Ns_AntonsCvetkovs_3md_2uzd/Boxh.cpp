#include "Box.h"

Box::Box(double w, double h, string bc) {
    Box::width = w;
    Box::height = h;
    Box::border_color = bc;
}

void Box::SetBox(double w, double h, string bc) {
    Box::width = w;
    Box::height = h;
    Box::border_color = bc;
}

BoxStruct Box::GetKatrsParameters() const {
    BoxStruct box;

    box.width = Box::width;
    box.height = Box::height;
    box.border_color = Box::border_color;

    return box;
}

void Box::PrintBox() const {
    cout << "Box Parameters:" << endl;
    cout << "Width: " << Box::width << "px" << endl;
    cout << "Height: " << Box::height << "px" << endl;
    cout << "Border Color: " << Box::border_color << endl;
}
