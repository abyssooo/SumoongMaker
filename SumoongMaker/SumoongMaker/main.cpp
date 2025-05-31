#include <iostream>
#include <memory>
#include "Character.h"
#include "ActionFactory.h"
#include "Ending.h"

using namespace std;

ActCategory chooseCategory() {
    cout << "\n선택할 수 있는 행동 카테고리:\n";
    cout << "1. 매력 (Charm)\n";
    cout << "2. 지능 (Intelligence)\n";
    cout << "3. 체력 (Strength)\n";
    cout << "4. 예술 (Art)\n";
    cout << "5. 휴식 (Rest)\n";
    cout << "6. 아르바이트 (Work)\n";

    int categoryInput;
    cout << "\n카테고리 번호를 입력하세요: ";
    cin >> categoryInput;

    switch (categoryInput) {
    case 1: return ActCategory::Charm;
    case 2: return ActCategory::Intelligence;
    case 3: return ActCategory::Strength;
    case 4: return ActCategory::Art;
    case 5: return ActCategory::Rest;
    case 6: return ActCategory::Work;
    default:
        cout << "잘못된 입력입니다. 기본값(휴식)으로 진행합니다.\n";
        return ActCategory::Rest;
    }
}

int chooseAction() {
    cout << "\n선택할 수 있는 행동들:\n";
    cout << "1. 첫 번째 행동\n";
    cout << "2. 두 번째 행동\n";
    cout << "3. 세 번째 행동\n";

    int option;
    cout << "\n행동 번호를 입력하세요: ";
    cin >> option;

    if (option < 1 || option > 3) {
        cout << "잘못된 입력입니다. 기본값(1)으로 진행합니다.\n";
        option = 1;
    }

    return option;
}

int main() {
    Character player("홍길동");
    cout << "게임을 시작합니다." << endl;

    for (int round = 1; round <= 12; ++round) {
        cout << "\n===== " << round << "번째 턴 시작 =====\n";

        for (int i = 0; i < 5; ++i) {
            cout << "\n--- 행동 " << i + 1 << " ---\n";

            ActCategory category = chooseCategory();
            int option = chooseAction();

            unique_ptr<Act> act = ActionFactory::create(category, option);
            cout << "\n선택한 행동: " << act->getName() << endl;
            player.applyAct(*act);
            cout << endl;
        }

        cout << "\n== " << round << "번째 턴 종료 후 현재 스탯 ==\n";
        player.showStats();
    }

    // 엔딩 출력
    Ending ending(player.getStat());
    cout << "\n게임 종료! 당신의 엔딩은: " << ending.getEnding() << endl;

    return 0;
}
