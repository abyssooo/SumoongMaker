#include <iostream>
#include <memory>
#include "Character.h"
#include "ActionFactory.h"
#include "ending.h" // 엔딩 추가

using namespace std;

int main() {
    Character player("홍길동");
    cout << "게임을 시작합니다.\n";

    const int MAX_WEEKS = 10;

    for (int week = 1; week <= MAX_WEEKS; ++week) {
        cout << "\n==== " << week << "주차 ====\n";

        cout << "1. 매력\n2. 지능\n3. 체력\n4. 예술\n5. 휴식\n6. 아르바이트\n";
        int categoryInput;
        cout << "카테고리 번호 입력: ";
        cin >> categoryInput;

        ActCategory category;
        switch (categoryInput) {
        case 1: category = ActCategory::Charm; break;
        case 2: category = ActCategory::Intelligence; break;
        case 3: category = ActCategory::Strength; break;
        case 4: category = ActCategory::Art; break;
        case 5: category = ActCategory::Rest; break;
        case 6: category = ActCategory::Work; break;
        default:
            cout << "잘못된 입력입니다.\n";
            continue;
        }

        cout << "1. 첫 번째 행동\n2. 두 번째 행동\n3. 세 번째 행동\n";
        int option;
        cout << "행동 번호 입력: ";
        cin >> option;

        unique_ptr<Act> act = ActionFactory::create(category, option);
        cout << "선택한 행동: " << act->getName() << "\n";
        player.applyAct(*act);
        player.showStatsWithAsciiArt();
    }

    // 루프 종료 후 엔딩 출력
    Ending ending(player.getStat());
    cout << "\n=== 당신의 엔딩은? ===\n";
    cout << ending.getEnding() << endl;

    return 0;
}
