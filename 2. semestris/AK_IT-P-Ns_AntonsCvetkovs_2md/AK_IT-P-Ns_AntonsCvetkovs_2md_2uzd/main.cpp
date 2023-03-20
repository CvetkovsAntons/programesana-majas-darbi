#include <iostream>

#include "Vector.h"

int main() {
    Vector v1, v2(1, 2, 3, 4, 5, 6), v3(1, 1, 1, 1, 1, 1);

    cout << "Original values\n"
         << "v1:\n" << v1 << "\n"
         << "v2:\n" << v2 << "\n"
         << "v3:\n" << v3
        << endl;

    cin >> v1;

    cout << "cin >> v1\n"
         << "v1:\n" << v1
         << endl;

    v3 = v1;

    cout << "v3 = v1" << endl;
    cout << "v3:\n" << v3 << endl;

    cout << "v1 + v2" << endl;
    cout << (v1 + v2) << endl;

    cout << "v3 - v1" << endl;
    cout << (v3 - v1) << endl;

    cout << "v1 * v2" << endl;
    cout << (v1 * v2) << endl;

    cout << "v1 > v2" << endl;

    if (v1 > v2) {
        cout << "TRUE" << endl;
        cout << "v1 is greater then v2\n" << endl;
    } else {
        cout << "FALSE" << endl;
        cout << "v1 is smaller or equal to v2\n" << endl;
    }

    cout << "v1 < v2" << endl;

    if (v1 < v2) {
        cout << "TRUE" << endl;
        cout << "v1 is smaller then v2\n" << endl;
    } else {
        cout << "FALSE" << endl;
        cout << "v1 is greater or equal to v2\n" << endl;
    }

    cout << "v1 >= v2" << endl;

    if (v1 >= v2) {
        cout << "TRUE" << endl;
        cout << "v1 is greater or equal to v2\n" << endl;
    } else {
        cout << "FALSE" << endl;
        cout << "v1 is smaller then v2\n" << endl;
    }

    cout << "v1 <= v2" << endl;

    if (v1 <= v2) {
        cout << "TRUE" << endl;
        cout << "v1 is smaller or equal to v2\n" << endl;
    } else {
        cout << "FALSE" << endl;
        cout << "v1 is greater then v2\n" << endl;
    }

    cout << "v1 == v2" << endl;

    if (v1 == v2) {
        cout << "TRUE" << endl;
        cout << "v1 is equal to v2\n" << endl;
    } else {
        cout << "FALSE" << endl;
        cout << "v1 is not equal to v2\n" << endl;
    }

    cout << "v1 != v2" << endl;

    if (v1 != v2) {
        cout << "TRUE" << endl;
        cout << "v1 is not equal to v2\n" << endl;
    } else {
        cout << "FALSE" << endl;
        cout << "v1 is equal to v2\n" << endl;
    }

    system("PAUSE");

    return 0;
}
