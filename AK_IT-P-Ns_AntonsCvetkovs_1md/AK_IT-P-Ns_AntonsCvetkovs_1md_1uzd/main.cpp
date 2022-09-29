#include <iostream>
#include <vector> // si biblioteka ir nepieciesama lai stradat ar masiviem (piem. pievienot jaunas vertibas)

using namespace std;

vector<int> findPalindromes() { // funkcija findPalindromes(), kas atrgriez masivu ar veseliem skaitliem

    vector<int> palindromes;  // mainigas 'palindormes' ar datu klasi vector<int>(array), kas pieniem tikati veselos skaitlus

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

        palindromes.push_back(i); // ja skaitlis ir palindrom, tad pievienojam to masiva
    }

    return palindromes; // atgriezam masivu ar palindromiem
}

int main() {
    vector<int> array = findPalindromes(); // mainigas 'array' ar datu klasi vector<int>(array), kas par savu vertibu pienem 'findPalindromes' funkcijas atgriezto masivu

    for (int i : array) { // cikls for, kas izvada visas vertibas no masiva 'array'
        cout << i << endl;
    }

    return 0;
}
