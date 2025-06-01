#pragma once

#include<iostream>
#include <string>
#include "Stat.h"
#include "Act.h"

using namespace std;

class Character {
private:
	string name;
	Stat stats;

public:
	Character(string name);
	void applyAct(const Act& act);
	void showStats() const;
	void showStatsWithAsciiArt() const;
	Stat getStat() const; // 반복 추가
};





