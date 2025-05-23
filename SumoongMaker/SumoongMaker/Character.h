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
	
};



