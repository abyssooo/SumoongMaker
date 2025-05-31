#include "Character.h"
#include <iostream>

Character::Character(string name) : name(name) {}

void Character::applyAct(const Act& act) {
    stats += act.getStatEffect();
    cout << act.getName() << " 행동을 수행했습니다." << endl;
}

void Character::showStats() const {
    cout << "\033[1;1H";
    cout << "\033[2J";    

    cout << "[현재 능력치]\n";
    cout << "매력     : " << stats.getCharm() << "\n";
    cout << "지능     : " << stats.getIntelligence() << "\n";
    cout << "체력     : " << stats.getStrength() << "\n";
    cout << "예술     : " << stats.getArt() << "\n";
    cout << "스트레스 : " << stats.getStress() << "\n";
    cout << "돈       : " << stats.getMoney() << "\n";
    cout << "------------------------" << endl;
}

}
