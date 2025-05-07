#pragma once

#include<iostream>
#include <string>
#include "Stat.h"

using namespace std;

class Act {

protected:

	Stat stat;

public:
	virtual ~Act() = default; //가상소멸자
	virtual string getName() const = 0; //자식클래스에서 이름을 정하게 하는 코드

};
