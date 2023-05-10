#include "Text.h"

Text::Text(string f, double s, string c, string d) {
    Text::font = f;
    Text::size = s;
    Text::color = c;
    Text::data = d;
}

void Text::SetText(string f, double s, string c, string d) {
    Text::font = f;
    Text::size = s;
    Text::color = c;
    Text::data = d;
}

TextStruct Text::GetKatrsParameters() const {
    TextStruct text;

    text.font = Text::font;
    text.size = Text::size;
    text.color = Text::color;
    text.data = Text::data;

    return text;
}

void Text::PrintText() const {
    cout << "Text Parameters:" << endl;
    cout << "Font: " << Text::font << endl;
    cout << "Size: " << Text::size << "px" << endl;
    cout << "Color: " << Text::color << endl;
    cout << "Data: " << Text::data << endl;
}