#include "MiniGame.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <ctime>     
#include <thread>
using namespace std;
using namespace std::chrono_literals;

void MiniGame::clearScreen() const {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H";
#endif
}

/* ===== public: 메뉴 → 실행 ===== */
Stat MiniGame::run() {
    bool success = false;
    int sel = 0;

    while ( true ) {
        cout << "\n=== Mini-Game Menu ===\n"
            << "1. 카드 짝 맞추기\n"
            << "2. 컵 맞추기\n"
            << "3. 동전 앞뒤 맞추기\n"
            << "4. 가위바위보\n"
            << "번호를 선택하세요: ";
        cin >> sel;

        switch ( sel ) {
        case 1: success = playCardMatch();          break;
        case 2: success = playCupGuess();           break;
        case 3: success = playCoinFlip();           break;
        case 4: success = playRockPaperScissors();  break;
        default:
            cout << "잘못된 입력입니다. 다시 선택하세요.\n";
            continue;          // 재입력
        }
        break;                      // 정상 선택 → 종료
    }
    return calcReward(success);
}

//1. 카드 짝 맞추기
bool MiniGame::playCardMatch() {
    int board[ 4 ][ 4 ] = {
         {11, 12, 13, 14},
         {21, 22, 23, 24},
         {31, 32, 33, 34},
         {41, 42, 43, 44}
    };

    int color[ 4 ][ 4 ] = {
        {0, 1, 2, 7},
        {3, 5, 6, 0},
        {2, 4, 6, 3},
        {4, 5, 1, 7}
    };

    int card1 = 0, card2 = 0;
    int row, col;

    do {
        clearScreen();

        // 카드판 출력
        for ( row = 0; row < 4; ++row ) {
            for ( col = 0; col < 4; ++col ) {
                bool opened = (board[ row ][ col ] <= 7) ||
                    (row == (card1 / 10 - 1) && col == (card1 % 10 - 1)) ||
                    (row == (card2 / 10 - 1) && col == (card2 % 10 - 1));

                if ( opened ) {
                    // 카드 색상 
                    cout << "\033[4" << color[ row ][ col ] << "m";
                    for ( int i = 0; i < 3; ++i ) {
                        cout << "\033[" << (row * 3 + 1 + i) << ";" << (col * 4 + 1) << "H";
                        cout << "    ";
                    }
                    cout << "\033[0m";
                }
                else {
                    // 카드 번호 출력 
                    for ( int i = 0; i < 3; ++i ) {
                        cout << "\033[" << (row * 3 + 1 + i) << ";" << (col * 4 + 1) << "H";
                        if ( i == 1 ) {
                            cout << " " << (row + 1) << (col + 1) << " ";
                        }
                        else {
                            cout << "    ";
                        }
                    }
                }
            }
        }

       cout << "\033[" << (4 * 3 + 2) << ";1H";  // 커서 아래쪽으로 이동

        // 카드 짝 맞추기 성공 시, board 업데이트
        if ( card1 != card2 &&
            color[ card1 / 10 - 1 ][ card1 % 10 - 1 ] == color[ card2 / 10 - 1 ][ card2 % 10 - 1 ] ) {

            board[ card1 / 10 - 1 ][ card1 % 10 - 1 ] = color[ card1 / 10 - 1 ][ card1 % 10 - 1 ];
            board[ card2 / 10 - 1 ][ card2 % 10 - 1 ] = color[ card2 / 10 - 1 ][ card2 % 10 - 1 ];

            // 다 맞췄는지 확인
            bool done = true;
            for ( row = 0; row < 4 && done; ++row ) {
                for ( col = 0; col < 4; ++col ) {
                    if ( board[ row ][ col ] > 7 ) {
                        done = false;
                        break;
                    }
                }
            }
            if ( done ) {
                clearScreen();
                cout << "\033[1;1H"; // 커서 위치 맨 위
                cout << "Success!!\n";
                this_thread::sleep_for(2s);
                return true;
            }
        }

        cout << "첫번째 카드를 선택하세요 (11~44): ";
        cin >> card1;
        cout << "두번째 카드를 선택하세요 (11~44): ";
        cin >> card2;

    } while (
        1 <= card1 / 10 && card1 / 10 <= 4 &&
        1 <= card1 % 10 && card1 % 10 <= 4 &&
        1 <= card2 / 10 && card2 / 10 <= 4 &&
        1 <= card2 % 10 && card2 % 10 <= 4
    );

    cout << "12회 안에 성공하지 못했습니다.\n";
    this_thread::sleep_for(2s);
    return false;
}

/* ===== 2. 컵 맞추기 ===== */
bool MiniGame::playCupGuess() {
    int ball = 0, cup = 0;
    srand(static_cast<unsigned int>(time(nullptr)));
    ball = rand() % 3 + 1;

    cout << "  ___    ___    ___  \n";
    cout << " |   |  |   |  |   | \n";
    cout << " | 1 |  | 2 |  | 3 | \n\n\n\n";

    cout << "구슬은 1~3번 컵 중 어디에? ";
    cin >> cup;

    if ( cup == ball ) {
        cout << "찾았다!\n";
        cout << "보상을 획득합니다.\n";
        this_thread::sleep_for(2s);
        return true;
    }
    else {
        cout << "놓쳤다!\n";
        this_thread::sleep_for(2s);
        return false;
    }
}

/* ===== 3. 동전 앞뒤 맞추기 ===== */
bool MiniGame::playCoinFlip() {
    int coin = uniform_int_distribution<int>(0, 1)(rng);
    cout << "동전 앞(0)/뒤(1) 선택: ";
    int user; cin >> user;
    cout << "결과는 " << (coin ? "뒤" : "앞") << "면!\n";
    sleepMs(2s);
    return user == coin;
}

/* ===== 4. 가위바위보 ===== */
bool MiniGame::playRockPaperScissors() {
    cout << "가위(1) 바위(2) 보(3) 선택: ";
    int user; cin >> user;

    int sys = uniform_int_distribution<int>(1, 3)(rng);
    const char* hand[ 4 ] = { "","가위","바위","보" };
    cout << "[system] " << hand[ sys ] << "!\n";
    sleepMs(2s);

    if ( user == sys ) return false; // 비김 = 실패 처리
    if ( (user == 1 && sys == 3) || (user == 2 && sys == 1) || (user == 3 && sys == 2) ) return true;
    return false;
}

/* ===== 성공/실패 → 보상 Stat ===== */
Stat MiniGame::calcReward(bool success) {
    Stat s;
    if ( success ) {
        cout << "보상: 돈 +5, 스트레스 -3\n";
        s.addStress(-3).addMoney(5);
    }
    else {
        cout << "패널티: 스트레스 +2, 돈 -3\n";
        s.addStress(2).addMoney(-3);
    }
    sleepMs(2s);
    return s;
}
