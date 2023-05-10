#include "Boss.h"

Boss::Boss(string name, int life, int level, int heads) : Monster(name, life, level) {
    Boss::heads = (heads > 0) ? heads : 0;
}

int Boss::GetHeads() const {
    return Boss::heads;
}

void Boss::Eat(Hero &hero) {
    Boss::life += hero.GetOriginalLife();
    Boss::heads += 1;
    hero.Hit(hero.GetLife());
}

void Boss::Print() {
    Boss::PrintCharacter();
    cout << "Level: " << Boss::level << endl;
    cout << "Heads: " << Boss::heads << endl;
}
