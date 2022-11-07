#include <iostream>

using namespace std;

int main() {
    for (int i = 100001; i < 1000000; i++) { // cikls for, kas parbaudis visus veselos skaitlus diapazona no 100 001 lidz 1 000 000 vai tie ir palindromi
        if (to_string(i)[0] != to_string(i)[5]) { // salidzinam pirmo un pedejo ciparu
            continue; // ja cipari nav vienadi, partraucam cikla atkarkojumu un sakam nakamo
        }

        if (to_string(i)[1] != to_string(i)[4]) { // salidzinam otro un piekto ciparu
            continue; // ja cipari nav vienadi, partraucam cikla atkarkojumu un sakam nakamo
        }

        if (to_string(i)[2] != to_string(i)[3]) { // salidzinam treso un ceturtu ciparu
            continue; // ja cipari nav vienadi, partraucam cikla atkarkojumu un sakam nakamo
        }

        cout << i << endl;
    }

    return 0;
}
