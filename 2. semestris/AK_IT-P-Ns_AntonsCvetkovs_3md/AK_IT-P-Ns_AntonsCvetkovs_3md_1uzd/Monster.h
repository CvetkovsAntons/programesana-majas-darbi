#ifndef AK_IT_P_NS_ANTONSCVETKOVS_3MD_1MD_MONSTER_H
#define AK_IT_P_NS_ANTONSCVETKOVS_3MD_1MD_MONSTER_H
#include "Character.h"

using namespace std;

class Monster : public Character {
public:
    Monster(string, int, int);
    int GetLevel() const;
    void Print();

protected:
    int level;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_3MD_1MD_MONSTER_H
