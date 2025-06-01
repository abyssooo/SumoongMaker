#include "Character.h"
#include <iostream>
#include <iomanip>
#include <algorithm> // max

using namespace std;

Stat Character::getStat() const {
    return stats;
}//초기화

static const char* ascii_art[] = {
    "        /\\   ♂ ♀   /\\        ",
    "       /  \\‾‾‾‾‾‾‾/  \\       ",
    "      /   ( ^ w ^ )   \\      ",
    "     |     ( ‿ )       |     ",
    "     |   \\_______/     |     ",
    "    /|     _____       |\\    ",
    "   / |    |     |      | \\   ",
    "  |  |    | [_] |      |  |  ",
    "  |  |    |_____|    __|  |  ",
    "  |  |   /       \\  /  |  |  ",
    "   \\_|__|         |____|_/   ",
    "      (__)       (__)        ",
    "      /  \\       /  \\        "
};

Character::Character(string name) : name(name) {}

void Character::applyAct(const Act& act) {
    stats += act.getStatEffect();
    cout << act.getName() << " 행동을 수행했습니다." << endl;
}

// 통합: 화면 클리어 + 좌측 스탯 + 우측 아트
void Character::showStatsWithAsciiArt() const {
    cout << "\033[1;1H";  // 커서 이동
    cout << "\033[2J";    // 화면 지우기

    const int statColWidth = 30;
    const int artLines = sizeof(ascii_art) / sizeof(ascii_art[0]);

    string statText[] = {
        "[현재 능력치]",
        "매력     : " + to_string(stats.getCharm()),
        "지능     : " + to_string(stats.getIntelligence()),
        "체력     : " + to_string(stats.getStrength()),
        "예술     : " + to_string(stats.getArt()),
        "스트레스 : " + to_string(stats.getStress()),
        "돈       : " + to_string(stats.getMoney()),
        "------------------------"
    };

    int statLineCount = sizeof(statText) / sizeof(statText[0]);
    int maxLines = max(statLineCount, artLines);

    for (int i = 0; i < maxLines; ++i) {
        if (i < statLineCount)
            cout << left << setw(statColWidth) << statText[i];
        else
            cout << setw(statColWidth) << " ";

        if (i < artLines)
            cout << ascii_art[i];

        cout << endl;
    }
}
