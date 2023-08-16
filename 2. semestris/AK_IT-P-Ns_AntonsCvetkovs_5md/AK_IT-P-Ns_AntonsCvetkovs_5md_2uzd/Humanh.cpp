#include "Human.h"

Human::Human() {}

Human::Human(const string& n, const string& s, int a) {
    Human::name = (n.length() > 0) ? n : "Name";
    Human::surname = (s.length() > 0) ? s : "Surname";
    Human::age = (a >= 0) ? a : 0;
}

void Human::printHuman() {
    cout << "\n==============================" << endl;
    cout << "          Person info.        " << endl;
    cout << "==============================" << endl;
    cout << "Name: " << Human::name << endl;
    cout << "Surname: " << Human::surname << endl;
    cout << "Age: " << Human::age << endl;
}
