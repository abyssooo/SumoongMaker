#include <iostream>
#include <memory>
#include <vector>
#include "Character.h"
#include "ActionFactory.h"
#include "Ending.h"

using namespace std;

int main() {
    char again;
    do {
        Character player("홍길동");
        cout << "게임을 시작합니다.\n";

        const int MAX_WEEKS = 10;

        for ( int week = 1; week <= MAX_WEEKS; ++week ) {
            cout << "\n==== " << week <<
                "주차 ====\n";

            ActCategory category;

            // 카테고리 선택 루프
            while ( true ) {
                cout << "선택할 수 있는 행동 카테고리:\n";
                cout << "1. 매력\n";
                cout << "2. 지능\n";
                cout << "3. 체력\n";
                cout << "4. 예술\n";
                cout << "5. 휴식\n";
                cout << "6. 아르바이트\n";
                cout << "카테고리 번호를 입력하세요: ";

                int categoryInput;
                cin >> categoryInput;

                switch ( categoryInput ) {
                case 1: category = ActCategory::Charm; break;
                case 2: category = ActCategory::Intelligence; break;
                case 3: category = ActCategory::Strength; break;
                case 4: category = ActCategory::Art; break;
                case 5: category = ActCategory::Rest; break;
                case 6: category = ActCategory::Work; break;
                default:
                    cout << "잘못된 입력입니다. 다시 선택해주세요.\n";
                    continue;
                }
                break;
            }

            // 행동 이름 출력
            vector<string> actions = ActionFactory::getActionNames(category);
            cout << "\n선택할 수 있는 행동들:\n";
            for ( size_t i = 0; i < actions.size(); ++i ) {
                cout << (i + 1) << ". " << actions[ i ] << endl;
            }
            cout << "0. 카테고리 선택으로 돌아가기\n";

            int option;
            cout << "행동 번호를 입력하세요: ";
            cin >> option;

            if ( option == 0 ) {
                cout << "카테고리 선택으로 돌아갑니다.\n";
                --week;
                continue;
            }

            unique_ptr<Act> act = ActionFactory::create(category, option);
            cout << "\n선택한 행동: " << act->getName() << "\n";

            player.applyAct(*act);
            player.showStatsWithAsciiArt();
        }

        // 엔딩 출력
        Ending ending(player.getStat());
        cout << "\n=== 당신의 엔딩은? ===\n";
        cout << ending.getEnding() << endl;

        // 다시 시작 여부
        cout << "\n다시 시작하시겠습니까? (y/n): ";
        cin >> again;

    } while ( again == 'y' || again == 'Y' );

    cout << "게임을 종료합니다.\n";
    return 0;
}
