#pragma once

#include<iostream>
#include <string>
#include "Stat.h"

using namespace std;

class Act {

protected:

	Stat stat;

public:
	virtual ~Act() = default; //����Ҹ���
	virtual string getName() const = 0; //�ڽ�Ŭ�������� �̸��� ���ϰ� �ϴ� �ڵ�

};
