#include "Character.h"
#include <iostream>

Character::Character(string name) : name(name) {}

void Character::applyAct(const Act& act) {
    stats += act.getStatEffect();
    cout << act.getName() << " 행동을 수행했습니다." << endl;
}

void Character::showStats() const {
    cout << "현재 능력치:" << endl;
    cout << "매력: " << stats.getCharm() << endl;
    cout << "지능: " << stats.getIntelligence() << endl;
    cout << "체력: " << stats.getStrength() << endl;
    cout << "예술: " << stats.getArt() << endl;
    cout << "스트레스: " << stats.getStress() << endl;
    cout << "돈: " << stats.getMoney() << endl;
}