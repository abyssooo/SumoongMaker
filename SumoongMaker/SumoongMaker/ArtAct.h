#pragma once

#include <string>
#include "Act.h"
#include "Stat.h"

using namespace std;

class ArtAct : public Act {

private:
	string name; //행동이름

public:

	// 생성자
	ArtAct(int actionNumber) {
		switch (actionNumber) {	
			case 1:
				name = "종이접기";
				stat.addArt(1);    // 예술 스탯 증가
				stat.addStress(1); // 스트레스 스탯 증가
				stat.addMoney(-1); // 돈 감소
				break;
				break;

			case 2:
				name = "전시회 보러가기";
				stat.addArt(2);    // 예술 스탯 증가
				stat.addStress(2); // 스트레스 스탯 증가
				stat.addMoney(-2); // 돈 감소
				break;

			case 3:
				name = "그림 그리기";
				stat.addArt(3);    // 예술 스탯 증가
				stat.addStress(3); // 스트레스 스탯 증가
				stat.addMoney(-3); // 돈 감소
				break;

			default:
				name = "알 수 없는 행동";
				break;
		}
	}

	// 행동 이름을 반환하는 함수
	string getName() const override {
		return name;
	}

	// 능력치 변화 반환
	Stat getStatEffect() const {
		return stat;
	}

};
