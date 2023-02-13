#ifndef AK_IT_P_NS_ANTONSCVETKOVS_1MD_CHARACTER_H
#define AK_IT_P_NS_ANTONSCVETKOVS_1MD_CHARACTER_H
#include <iostream>

using namespace std;

class Character {
public:
    Character(string, int);
    bool Hit(int);
    void Go(char);
    int GetLife() const;
    char PlayerMove() const;
    void PrintCharacter();
    ~Character();

private:
    string name;
    int life;
    char path[10] = {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-',};
};


#endif //AK_IT_P_NS_ANTONSCVETKOVS_1MD_CHARACTER_H
