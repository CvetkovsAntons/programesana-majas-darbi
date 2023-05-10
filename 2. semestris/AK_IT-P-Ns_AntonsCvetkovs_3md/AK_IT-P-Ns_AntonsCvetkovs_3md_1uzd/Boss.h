#ifndef AK_IT_P_NS_ANTONSCVETKOVS_3MD_1MD_BOSS_H
#define AK_IT_P_NS_ANTONSCVETKOVS_3MD_1MD_BOSS_H
#include "Hero.h"

using namespace std;

class Boss : public Monster {
public:
    Boss(string, int, int, int);
    int GetHeads() const;
    void Eat(Hero &);
    void Print();

protected:
    int heads;
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_3MD_1MD_BOSS_H
