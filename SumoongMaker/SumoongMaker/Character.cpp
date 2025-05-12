#include "Character.h"
#include <iostream>

Character::Character(string name) : name(name) {}

void Character::applyAct(const Act& act) {
    stats += act.getStatEffect();
    cout << act.getName() << " �ൿ�� �����߽��ϴ�." << endl;
}

void Character::showStats() const {
    cout << "���� �ɷ�ġ:" << endl;
    cout << "�ŷ�: " << stats.getCharm() << endl;
    cout << "����: " << stats.getIntelligence() << endl;
    cout << "ü��: " << stats.getStrength() << endl;
    cout << "����: " << stats.getArt() << endl;
    cout << "��Ʈ����: " << stats.getStress() << endl;
    cout << "��: " << stats.getMoney() << endl;
}