#include <iostream>
#include "Boss.h"

using namespace std;

int main() {
    Hero hero("Crewmate", 10, 3);
    Monster monster("Imposter", 3, 1);
    Boss boss("Amogus", 100, 20, 0);

    cout << "HERO Print():" << endl;
    hero.Print();
    cout << "\nMONSTER Print():" << endl;
    monster.Print();
    cout << "\nBOSS Print():" << endl;
    boss.Print();

    cout << "\n\nHERO kills MONSTER:" << endl;
    hero.Kill(monster);
    cout << "\nBOSS eats HERO:" << endl;
    boss.Eat(hero);

    cout << "\n\nHERO Print():" << endl;
    hero.Print();
    cout << "\nMONSTER Print():" << endl;
    monster.Print();
    cout << "\nBOSS Print():" << endl;
    boss.Print();

    system("PAUSE");

    cout << "\n\n";

    return 0;
}
