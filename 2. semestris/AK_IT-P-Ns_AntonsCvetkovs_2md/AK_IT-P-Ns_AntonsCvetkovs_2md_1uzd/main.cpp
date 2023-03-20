#include <iostream>
#include "Time.h"

using namespace std;

int main() {
    Time t1(12, 30, 30), t2, t3(23, 59, 59);

    cout << "Original values:\n"
         << "Time 1: " << t1
         << "Time 2: " <<  t2
         << "Time 3: " <<  t3 << endl;

    t1 = t1;

    t1 = t2 = t3;

    cout << "Time 1 = Time 2 = Time 3\n"
         << "Time 1: " << t1
         << "Time 2: " <<  t2
         << "Time 3: " <<  t3 << endl;

    t1++;

    cout << "Time 1 ++\n"
         << t1 << endl;

    t1--;

    cout << "Time 1 --\n"
         << t1 << endl;

    ++t1;

    cout << "++ Time 1\n"
         << t1 << endl;

    --t1;

    cout << "-- Time 1\n"
         << t1 << endl;

    cin >> t2;

    cout << "Time 2 >>\n"
         << t2 << endl;

    cout << "Time 1 > Time 2" << endl;

    if (t1 > t2) {
        cout << "True\n"
             << "Time 1 is greater then Time 2\n"
             << "Time 1: " << t1
             << "Time 2: " << t2
             << endl;
    } else {
        cout << "False\n"
             << "Time 1 is smaller or equal to Time 2\n"
             << "Time 1: " << t1
             << "Time 2: " << t2
             << endl;
    }

    cout << "Time 1 < Time 2" << endl;

    if (t1 < t2) {
        cout << "True\n"
             << "Time 1 is smaller then Time 2\n"
             << "Time 1: " << t1
             << "Time 2: " << t2
             << endl;
    } else {
        cout << "False\n"
             << "Time 1 is greater or equal to Time 2\n"
             << "Time 1: " << t1
             << "Time 2: " << t2
             << endl;
    }

    cout << "Time 1 >= Time 2" << endl;

    if (t1 >= t2) {
        cout << "True\n"
             << "Time 1 is greater or equal to Time 2\n"
             << "Time 1: " << t1
             << "Time 2: " << t2
             << endl;
    } else {
        cout << "False\n"
             << "Time 1 is smaller then Time 2\n"
             << "Time 1: " << t1
             << "Time 2: " << t2
             << endl;
    }

    cout << "Time 1 <= Time 2" << endl;

    if (t1 <= t2) {
        cout << "True \n"
             << "Time 1 is smaller or equal to Time 2\n"
             << "Time 1: " << t1
             << "Time 2: " <<  t2
             << endl;
    } else {
        cout << "False \n"
             << "Time 1 is greater then Time 2\n"
             << "Time 1: " << t1
             << "Time 2: " <<  t2
             << endl;
    }

    cout << "Time 1 == Time 2" << endl;

    if (t1 == t2) {
        cout << "True \n"
             << "Time 1 is equal to Time 2\n"
             << "Time 1: " << t1
             << "Time 2: " <<  t2
             << endl;
    } else {
        cout << "False \n"
             << "Time 1 is not equal to Time 2\n"
             << "Time 1: " << t1
             << "Time 2: " <<  t2
             << endl;
    }

    cout << "Time 1 != Time 2" << endl;

    if (t1 != t2) {
        cout << "True \n"
             << "Time 1 is not equal to Time 2\n"
             << "Time 1: " << t1
             << "Time 2: " <<  t2
             << endl;
    } else {
        cout << "False \n"
             << "Time 1 is equal to Time 2\n"
             << "Time 1: " << t1
             << "Time 2: " <<  t2
             << endl;
    }

    system("PAUSE");

    return 0;
}
