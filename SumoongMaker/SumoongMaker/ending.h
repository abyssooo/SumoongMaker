#define Ending_h

#include <string>
#include "Stat.h"

using namespace std;

class Ending {
public:
    // 생성자: 게임이 끝난 후 최종 Stat을 입력받음
    Ending(const Stat& finalStat);

    // 엔딩 이름을 반환하는 함수
    string getEnding() const;

private:
    Stat playerStat; // 플레이어의 최종 스탯

    // 각 엔딩을 판단하는 함수들
    bool isBadEnding() const;
    bool isHappyEnding() const;
    bool isCharmEnding() const;
    bool isStrengthEnding() const;
    bool isArtEnding() const;
    bool isIntelligenceEnding() const;
};
