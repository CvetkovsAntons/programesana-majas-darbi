#include <iostream>
#include "Helpers.h"
#include "Helpersh.cpp"
#include "Queue.h"
#include "Queueh.cpp"

using namespace std;

int main() {
    // genereju random size katram Queue
    int sizeOfQueueInt = randomNumber(5, 10);
    int sizeOfQueueFloat = randomNumber(5, 10);
    int sizeOfQueueChar= randomNumber(5, 10);

    Queue<int> queueInt(sizeOfQueueInt);
    Queue<float> queueFloat(sizeOfQueueFloat);
    Queue<char> queueChar(sizeOfQueueChar);

    // aizpildu visus masivus ar random elementu skaitu
    for (int i = 0; i < randomNumber(3, sizeOfQueueInt); i++) {
        queueInt.enqueue(randomNumber(1, 100));
    }

    for (int i = 0; i < randomNumber(3, sizeOfQueueFloat); i++) {
        float randomFloat = randomNumber(1.0f, 10.0f);
        queueFloat.enqueue(randomFloat);
    }

    for (int i = 0; i < randomNumber(3, sizeOfQueueChar); i++) {
        queueChar.enqueue(static_cast<char>(randomNumber(32, 126)));
    }

    cout << "QueueINT after creation" << endl;
    queueInt.PrintQueue();
    cout << "\nQueueFLOAT after creation" << endl;
    queueFloat.PrintQueue();
    cout << "\nQueueChar after creation" << endl;
    queueChar.PrintQueue();

    // nonemu no visim masiviem random elementu skaitu
    cout << "\nQueueINT removed values: " << endl;
    int random = (queueInt.getIndex() == 1) ? 1 : randomNumber(1, queueInt.getIndex());
    for (int i = 0; i < random; i++) {
        cout << i << ": " << queueInt.dequeue() << endl;
    }

    cout << "\nQueueFLOAT removed values: " << endl;
    random = (queueInt.getIndex() == 1) ? 1 : randomNumber(1, queueFloat.getIndex());
    for (int i = 0; i <  random; i++) {
        cout << i << ": " << queueFloat.dequeue() << endl;
    }

    cout << "\nQueueCHAR removed values: " << endl;
    random = (queueInt.getIndex() == 1) ? 1 : randomNumber(1, queueChar.getIndex());
    for (int i = 0; i < random; i++) {
        cout << i << ": " << static_cast<char>(queueChar.dequeue()) << endl;
    }

    cout << "\nQueueINT after removing values" << endl;
    queueInt.PrintQueue();
    cout << "\nQueueFLOAT after removing values" << endl;
    queueFloat.PrintQueue();
    cout << "\nQueueChar after removing values" << endl;
    queueChar.PrintQueue();

    cout << "\nQueueINT append values" << endl;
    random = ((queueInt.getSize() - queueInt.getIndex()) == 0) ? 0 : randomNumber(1, queueInt.getSize() -  queueInt.getIndex());
    for (int i = 0; i < random; i++) {
        queueInt.enqueue(randomNumber(1, 100));
    }

    cout << "\nQueueFLOAT append values" << endl;
    random = ((queueFloat.getSize() - queueFloat.getIndex()) == 0) ? 0 : randomNumber(1, queueFloat.getSize() -  queueFloat.getIndex());
    for (int i = 0; i < random; i++) {
        queueFloat.enqueue(randomNumber(1.0f, 100.0f));
    }


    cout << "\nQueueCHAR append values" << endl;
    random = ((queueChar.getSize() - queueChar.getIndex()) == 0) ? 0 : randomNumber(1, queueChar.getSize() -  queueChar.getIndex());
    for (int i = 0; i < random; i++) {
        queueChar.enqueue(static_cast<char>(randomNumber(32, 126)));
    }

    cout << "\nQueueINT after adding values:" << endl;
    queueInt.PrintQueue();
    cout << "\nQueueFLOAT after adding values:" << endl;
    queueFloat.PrintQueue();
    cout << "\nQueueChar after adding values:" << endl;
    queueChar.PrintQueue();

    system("PAUSE");

    return 0;
}
