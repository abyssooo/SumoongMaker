#include <iostream>
#include <memory>
#include "Character.h"
#include "ActionFactory.h"

using namespace std;

int main() {
    // 캐릭터 생성
    Character player("홍길동");

    // 게임 시작 메시지
    cout << "게임을 시작합니다. "  << endl;

    // 행동 카테고리 출력
    cout << "\n선택할 수 있는 행동 카테고리:\n";
    cout << "1. 매력 (Charm)\n";
    cout << "2. 지능 (Intelligence)\n";
    cout << "3. 체력 (Strength)\n";
    cout << "4. 예술 (Art)\n";
    cout << "5. 휴식 (Rest)\n";
    cout << "6. 아르바이트 (Work)\n";

    // 카테고리 선택
    int categoryInput;
    cout << "\n카테고리 번호를 입력하세요: ";
    cin >> categoryInput;

    ActCategory category;

    // 카테고리 입력에 맞는 ActCategory 설정
    switch (categoryInput) {
    case 1:
        category = ActCategory::Charm;
        break;
    case 2:
        category = ActCategory::Intelligence;
        break;
    case 3:
        category = ActCategory::Strength;
        break;
    case 4:
        category = ActCategory::Art;
        break;
    case 5:
        category = ActCategory::Rest;
        break;
    case 6:
        category = ActCategory::Work;
        break;
    default:
        cout << "잘못된 입력입니다." << endl;
        return 1;
    }

    // 해당 카테고리의 행동 출력
    cout << "\n선택할 수 있는 행동들:\n";
    cout << "1. 첫 번째 행동\n";
    cout << "2. 두 번째 행동\n";
    cout << "3. 세 번째 행동\n";

    // 행동 선택
    int option;
    cout << "\n행동 번호를 입력하세요: ";
    cin >> option;

    // 행동 생성
    unique_ptr<Act> act = ActionFactory::create(category, option);

    // 선택한 행동 출력
    cout << "\n선택한 행동: " << act->getName() << endl;

    // 행동 적용
    player.applyAct(*act);

    // 스탯 출력
    cout << "\n현재 스탯:\n";
    player.showStats();

    return 0;
}
