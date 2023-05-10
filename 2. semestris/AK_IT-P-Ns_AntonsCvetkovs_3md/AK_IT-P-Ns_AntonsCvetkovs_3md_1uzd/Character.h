#ifndef AK_IT_P_NS_ANTONSCVETKOVS_3MD_1MD_CHARACTER_H
#define AK_IT_P_NS_ANTONSCVETKOVS_3MD_1MD_CHARACTER_H
#include <iostream>

using namespace std;

class Character {
public:
    Character(string, int);
    bool Hit(int);
    void Go(char);
    int GetLife() const;
    int GetOriginalLife() const;
    void PrintCharacter();
    ~Character();

protected:
    string name;
    int life;
    int originalLife;
    char path[10] = {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-',};
};

#endif //AK_IT_P_NS_ANTONSCVETKOVS_3MD_1MD_CHARACTER_H
