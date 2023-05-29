#ifndef AK_IT_P_NS_ANTONSCVETKOVS_5MD_1UZD_QUEUE_H
#define AK_IT_P_NS_ANTONSCVETKOVS_5MD_1UZD_QUEUE_H
#include <iostream>

using namespace std;

template <class Type>
class Queue {
public:
    explicit Queue(int);
    void enqueue(Type X);
    Type dequeue();
    void PrintQueue();
    int getSize() const;
    int getIndex() const;
    ~Queue();

private:
    Type *queue;
    int size;
    int index;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_5MD_1UZD_QUEUE_H
