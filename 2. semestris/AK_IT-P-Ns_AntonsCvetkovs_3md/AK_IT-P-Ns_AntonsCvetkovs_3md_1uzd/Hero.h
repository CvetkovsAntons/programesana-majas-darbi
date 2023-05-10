#ifndef AK_IT_P_NS_ANTONSCVETKOVS_3MD_1MD_HERO_H
#define AK_IT_P_NS_ANTONSCVETKOVS_3MD_1MD_HERO_H
#include "Monster.h"

using namespace std;

class Hero : public Character {
public:
    Hero(string, int, int);
    void Kill(Monster &);
    void Print();

protected:
    int experience;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_3MD_1MD_HERO_H
