#pragma once

#include <string>
#include "Act.h"
#include "Stat.h"

using namespace std;

class ArtAct : public Act {

private:
	string name; //�ൿ�̸�

public:

	// ������
	ArtAct(int actionNumber) {
		switch (actionNumber) {	
			case 1:
				name = "��������";
				stat.addArt(1);    // ���� ���� ����
				stat.addStress(1); // ��Ʈ���� ���� ����
				stat.addMoney(-1); // �� ����
				break;
				break;

			case 2:
				name = "����ȸ ��������";
				stat.addArt(2);    // ���� ���� ����
				stat.addStress(2); // ��Ʈ���� ���� ����
				stat.addMoney(-2); // �� ����
				break;

			case 3:
				name = "�׸� �׸���";
				stat.addArt(3);    // ���� ���� ����
				stat.addStress(3); // ��Ʈ���� ���� ����
				stat.addMoney(-3); // �� ����
				break;

			default:
				name = "�� �� ���� �ൿ";
				break;
		}
	}

	// �ൿ �̸��� ��ȯ�ϴ� �Լ�
	string getName() const override {
		return name;
	}

	// �ɷ�ġ ��ȭ ��ȯ
	Stat getStatEffect() const {
		return stat;
	}

};
