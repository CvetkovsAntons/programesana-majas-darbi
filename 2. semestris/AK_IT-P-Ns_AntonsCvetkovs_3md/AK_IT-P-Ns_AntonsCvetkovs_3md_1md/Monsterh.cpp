#include "Monster.h"

Monster::Monster(string name, int life, int level) : Character(name, life) {
    Monster::level = (level > 0) ? level : 1;
}

Monster::~Monster() {
    cout << "Monster died" << endl;
}

int Monster::GetLevel() const {
    return Monster::level;
}

void Monster::Print() {
    Monster::PrintCharacter();
    cout << "Level: " << Monster::level << endl;
}