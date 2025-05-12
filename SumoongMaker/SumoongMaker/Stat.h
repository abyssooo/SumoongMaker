#pragma once

#include<iostream>
#include <string>

using namespace std;

class Stat {

private:
	int charm;
	int intelligence;
	int strength;
	int art;
	int stress;
	int money;

public:
	Stat() : charm(0), intelligence(0), strength(0), art(0), stress(0), money(0) {} // �⺻�� 0
	// �ɷ�ġ �ʱⰪ ����, �Ű������� �޴� ������
	Stat(int c, int i, int s, int a, int st, int m)
		: charm(c), intelligence(i), strength(s), art(a), stress(st), money(m) {
	}

	// getter, �б� �����̶� const
	int getCharm() const { return charm; }
	int getIntelligence() const { return intelligence; }
	int getStrength() const { return strength; }
	int getArt() const { return art; }
	int getStress() const { return stress; }
	int getMoney() const { return money; }


	// setter
	void setCharm(int c) { charm = c; }
	void setIntelligence(int i) { intelligence = i; }
	void setStrength(int s) { strength = s; }
	void setArt(int a) { art = a; }
	void setStress(int st) { stress = st; }
	void setMoney(int m) { money = m; }

	//���ȴ����Լ�, �κм�����
	Stat& addCharm(int val) { charm += val; return *this; }
	Stat& addIntelligence(int val) { intelligence += val; return *this; }
	Stat& addStrength(int val) { strength += val; return *this; }
	Stat& addArt(int val) { art += val; return *this; }
	Stat& addStress(int val) { stress += val; return *this; }
	Stat& addMoney(int val) { money += val; return *this; }

	// ������ �����ε�, ��ü���ȴ����� �����ϰ� ��, �ٵ� �ʿ��������? �ϴ� ����
	Stat& operator+=(const Stat& other) {
		charm += other.charm;
		intelligence += other.intelligence;
		strength += other.strength;
		art += other.art;
		stress += other.stress;
		money += other.money;
		return *this;
	}


};
