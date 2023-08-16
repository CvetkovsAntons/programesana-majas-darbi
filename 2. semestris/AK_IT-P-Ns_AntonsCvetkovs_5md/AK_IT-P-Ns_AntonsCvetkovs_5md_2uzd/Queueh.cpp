#include "Queue.h"
#include "Human.h"

template <class Type>
Queue<Type>::Queue(int s) { // daleji panemts no jusu piemera :)
    if (s < 1) {
        cout << "Wrong size of array has been passed (min. value: 1)! Program abort!" << endl;
        system("PAUSE");
        exit(1);
    } else {
        Queue<Type>::queue = new Type [s];
    }

    if (Queue<Type>::queue == NULL) {
        cout << "Not enough memory! Program abort!" << endl;
        system("PAUSE");
        exit(1);
    }

    Queue<Type>::size = s;
    Queue<Type>::index = 0;
}

template<class Type>
void Queue<Type>::enqueue(Type X) { // panemts no jusu piemera :)
    if (Queue<Type>::index == Queue<Type>::size) {
        cout << "Array is full! Operation abort!" << endl;
        system("PAUSE");
        return;
    }

    Queue<Type>::queue[Queue<Type>::index] = X;
    Queue<Type>::index++;
}

template<class Type>
Type Queue<Type>::dequeue() {
    Type* oldQueue = Queue<Type>::queue; // izveidoju veca masiva kopiju
    Type removedValue = oldQueue[0]; // saglabaju pirmo veribu
    Queue<Type>::index -= 1; // samazinu index vertibu

    Queue<Type>::queue = new Type[Queue<Type>::size]; // izveidoju jaunu masivu

    for (int i = 0; i < Queue<Type>::index; i++) {
        Queue<Type>::queue[i] = oldQueue[i + 1]; // parnesu vertibas pa vienam uz prieksu
    }

    delete[] oldQueue; // izdesu veco masivu

    return removedValue; // atgriezu izdezsto vertibu
}


template<class Type>
void Queue<Type>::PrintQueue() {
    for (int i = 0; i < Queue<Type>::index; i++) {
        Queue<Type>::queue[i].printHuman();
    }
}

template<class Type>
int Queue<Type>::getSize() const {
    return Queue<Type>::size;
}

template<class Type>
int Queue<Type>::getIndex() const {
    return Queue<Type>::index;
}

template<class Type>
Queue<Type>::~Queue() {
    delete[] Queue<Type>::queue;
}