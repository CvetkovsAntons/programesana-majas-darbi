#include <iostream>
#include <vector>
#include "eTalons.h"
#include "BraucienuskET.h"
#include "DiennaktsET.h"
#include "PersoniskaisET.h"

using namespace std;

int main() {
    vector<eTalons*> eTalonsArray; // deklareju masivu, kas glabs objektus, kas tiek atvasinati no eTalons klases

    PersoniskaisET personiskaisEt1(10, "Antons", "Zarkovs"), personiskaisEt2(1, "Antons", "Cvetkovs"); // deklareju PersonisakisET objektus
    DiennaktsET diennaktsEt1, diennaktsEt2; // deklareju DiennaktsET objektus
    BraucienuskET braucienuskEt1(3), braucienuskEt2(6); // deklareju BraucienuskET objektus

    eTalonsArray.push_back(&personiskaisEt1);
    eTalonsArray.push_back(&personiskaisEt2);
    eTalonsArray.push_back(&diennaktsEt1);
    eTalonsArray.push_back(&diennaktsEt2);
    eTalonsArray.push_back(&braucienuskEt1);
    eTalonsArray.push_back(&braucienuskEt2);

    for (eTalons* etalons : eTalonsArray) { // foreach loop, kas iet caur eTalonsArray
        cout << endl;

        etalons->Print();
        etalons->Use();
        etalons->Use();
        etalons->Add(randomNumber(1, 5));
        etalons->Use();
        etalons->Use();
        etalons->Add(randomNumber(1, 5));
        etalons->Print();
    }
}
