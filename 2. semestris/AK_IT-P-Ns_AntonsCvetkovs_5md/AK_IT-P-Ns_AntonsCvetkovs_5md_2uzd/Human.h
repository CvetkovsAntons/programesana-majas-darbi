#ifndef AK_IT_P_NS_ANTONSCVETKOVS_5MD_2UZD_HUMAN_H
#define AK_IT_P_NS_ANTONSCVETKOVS_5MD_2UZD_HUMAN_H
#include <iostream>

using namespace std;

class Human {
public:
    Human();
    Human(string, string, int);
    void printHuman();

private:
    string name;
    string surname;
    int age;
};
#endif //AK_IT_P_NS_ANTONSCVETKOVS_5MD_2UZD_HUMAN_H
