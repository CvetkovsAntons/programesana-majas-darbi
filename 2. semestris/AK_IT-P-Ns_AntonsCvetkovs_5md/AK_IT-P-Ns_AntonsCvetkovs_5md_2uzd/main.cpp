#include <iostream>
#include "Human.h"
#include "Queue.h"
#include "Queueh.cpp"

using namespace std;

int main() {
    Queue<Human> HumanQueue(10);

    cout << "Queue<Human> of size " << HumanQueue.getSize() << " has been created" << endl;
    cout << "Pievinoju cilvekus rindaa" << endl;

    HumanQueue.enqueue(Human("Antons", "Cvetkovs", 21));
    HumanQueue.enqueue(Human("Leonids", "Malcevs", 23));
    HumanQueue.enqueue(Human("Arturs", "Solovjevs", 25));
    HumanQueue.enqueue(Human("Jevgenijs", "Timofejevs", 24));
    HumanQueue.enqueue(Human("Rolands", "Skrebutens", 26));
    HumanQueue.enqueue(Human("Antons", "Zarkovs", 25));

    HumanQueue.PrintQueue();

    cout << "\n\n\nIznemu divus cilvekus no rindas" << endl;

    HumanQueue.dequeue();
    HumanQueue.dequeue();

    HumanQueue.PrintQueue();

    cout << "\n\n\nPievienoju cilveku rindaa" << endl;

    HumanQueue.enqueue(Human("Viktors", "Valgis", 25));

    HumanQueue.PrintQueue();

    return 0;
}
