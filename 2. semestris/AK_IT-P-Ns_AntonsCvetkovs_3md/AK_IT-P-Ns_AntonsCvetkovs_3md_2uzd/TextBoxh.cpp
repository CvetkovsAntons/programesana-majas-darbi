#include "TextBox.h"

TextBox::TextBox(string f, double s, string c, string d, double w, double h, string bc) : Text(f, s, c, d), Box(w, h, bc) {}

void TextBox::SetTextBox(string f, double s, string c, string d, double w, double h, string bc) {
    TextBox::SetText(f, s, c, d);
    TextBox::SetBox(w, h, bc);
}

void TextBox::PrintTextBox() const {
    TextStruct text = Text::GetKatrsParameters();
    BoxStruct box = Box::GetKatrsParameters();

    cout << "TextBox Parameters:" << endl;
    cout << "Font: " << text.font << endl;
    cout << "Size: " << text.size << "px" << endl;
    cout << "Color: " << text.color << endl;
    cout << "Data: " << text.data << endl;
    cout << "Width: " << box.width << "px" << endl;
    cout << "Height: " << box.height << "px" << endl;
    cout << "Border Color: " << box.border_color << endl;
}
