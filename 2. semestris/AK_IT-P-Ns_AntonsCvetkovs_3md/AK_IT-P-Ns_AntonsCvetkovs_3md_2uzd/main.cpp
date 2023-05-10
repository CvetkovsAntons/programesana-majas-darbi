#include <iostream>
#include "TextBox.h"

using namespace std;

int main() {
    TextBox textBox("Calibri (light)", 24, "#FF0000", "Lorem Ipsum", 40, 20, "#FF0000");

    textBox.PrintText();

    cout << "\n";

    textBox.PrintBox();

    cout << "\nSetText" << endl;

    textBox.SetText("Arial", 16, "#FFFFFF", "Ipsum Lorem");

    cout << "\nSetBox" << endl;

    textBox.SetBox(22, 11, "#FFFFFF");

    cout << "\n";

    textBox.PrintText();

    cout << "\n";

    textBox.PrintBox();

    cout << "\nSetTextBox" << endl;

    textBox.SetTextBox("Sans-Serif", 36, "#FF3456", "Lorem Ipsum Ipsum Lorem", 60, 60, "#FF3456");

    cout << "\n";

    textBox.PrintTextBox();

    system("PAUSE");

    return 0;
}
