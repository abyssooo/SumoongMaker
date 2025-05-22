#include "Ending.h"
#include <algorithm>

using namespace std;

Ending::Ending(const Stat& finalStat) : playerStat(finalStat) {}

bool Ending::isBadEnding() const {
    return playerStat.getStress() >= 100;
}

bool Ending::isHappyEnding() const {
    int averageStat = (playerStat.getCharm() + playerStat.getIntelligence() + playerStat.getStrength() + playerStat.getArt()) / 4;
    return playerStat.getCharm() >= averageStat &&
           playerStat.getIntelligence() >= averageStat &&
           playerStat.getStrength() >= averageStat &&
           playerStat.getArt() >= averageStat;
}

bool Ending::isCharmEnding() const {
    int highestStat = max({playerStat.getCharm(), playerStat.getIntelligence(), playerStat.getStrength(), playerStat.getArt()});
    return playerStat.getCharm() == highestStat;
}

bool Ending::isStrengthEnding() const {
    int highestStat = max({playerStat.getCharm(), playerStat.getIntelligence(), playerStat.getStrength(), playerStat.getArt()});
    return playerStat.getStrength() == highestStat;
}

bool Ending::isArtEnding() const {
    int highestStat = max({playerStat.getCharm(), playerStat.getIntelligence(), playerStat.getStrength(), playerStat.getArt()});
    return playerStat.getArt() == highestStat;
}

bool Ending::isIntelligenceEnding() const {
    int highestStat = max({playerStat.getCharm(), playerStat.getIntelligence(), playerStat.getStrength(), playerStat.getArt()});
    return playerStat.getIntelligence() == highestStat;
}

string Ending::getEnding() const {
    if (isBadEnding()) return "배드엔딩: 교도소 마스코트";
    if (isHappyEnding()) return "해피엔딩: 상명대 마스코트";
    if (isCharmEnding()) return "매력 엔딩: 동물원 마스코트";
    if (isStrengthEnding()) return "체력 엔딩: 스포츠 구단 마스코트";
    if (isArtEnding()) return "예술 엔딩: 미술관 마스코트";
    if (isIntelligenceEnding()) return "지능 엔딩: 멘사 마스코트";

    return "평범한 엔딩";
}
