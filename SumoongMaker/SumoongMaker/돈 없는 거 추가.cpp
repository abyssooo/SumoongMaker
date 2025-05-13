#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <utility>
#include <algorithm>

using namespace std;

// ------------------------- Stat 클래스 -------------------------
class Stat {
private:
    int charm, intelligence, strength, art, stress, money;

public:
    Stat() : charm(0), intelligence(0), strength(0), art(0), stress(0), money(0) {}
    Stat(int c, int i, int s, int a, int st, int m)
        : charm(c), intelligence(i), strength(s), art(a), stress(st), money(m) {
    }

    int getCharm() const { return charm; }
    int getIntelligence() const { return intelligence; }
    int getStrength() const { return strength; }
    int getArt() const { return art; }
    int getStress() const { return stress; }
    int getMoney() const { return money; }

    Stat& addCharm(int val) { charm += val; return *this; }
    Stat& addIntelligence(int val) { intelligence += val; return *this; }
    Stat& addStrength(int val) { strength += val; return *this; }
    Stat& addArt(int val) { art += val; return *this; }
    Stat& addStress(int val) { stress += val; return *this; }
    Stat& addMoney(int val) { money += val; return *this; }

    Stat& operator+=(const Stat& other) {
        charm += other.charm;
        intelligence += other.intelligence;
        strength += other.strength;
        art += other.art;
        stress += other.stress;
        money += other.money;
        return *this;
    }

    void show() const {
        cout << "매력: " << charm << "\n지능: " << intelligence
            << "\n체력: " << strength << "\n예술: " << art
            << "\n스트레스: " << stress << "\n재화: " << money << endl;
    }
};

// ------------------------- 엔딩 결정 함수 -------------------------
string determineEnding(const Stat& s) {
    if (s.getStress() >= 100) return "배드엔딩: 교도소 마스코트";

    int charm = s.getCharm();
    int intelligence = s.getIntelligence();
    int strength = s.getStrength();
    int art = s.getArt();

    int highest = max({ charm, intelligence, strength, art });
    int average = (charm + intelligence + strength + art) / 4;

    if (charm >= average && intelligence >= average && strength >= average && art >= average)
        return "해피엔딩: 상명대 마스코트";
    if (charm == highest) return "매력 엔딩: 동물원 마스코트";
    if (strength == highest) return "체력 엔딩: 스포츠 구단 마스코트";
    if (art == highest) return "예술 엔딩: 미술관 마스코트";
    if (intelligence == highest) return "지능 엔딩: 멘사 마스코트";

    return "평범한 엔딩";
}

// ------------------------- Act 클래스 -------------------------
class Act {
public:
    virtual ~Act() = default;
    virtual string getName() const = 0;
    virtual Stat getStatEffect() const = 0;
};

// ------------------------- ActCategory -------------------------
enum class ActCategory {
    Charm, Intelligence, Strength, Art, Rest, Work
};

// ------------------------- Character 클래스 -------------------------
class Character {
private:
    string name;
    Stat stat;

public:
    Character(string n) : name(n), stat(0, 0, 0, 0, 0, 3) {}

    void applyAct(const Act& act) {
        stat += act.getStatEffect();
    }

    const Stat& getStat() const {
        return stat;
    }
};

// ------------------------- Stat 출력 함수 -------------------------
void printStatBox(const Character& player) {
    const Stat& s = player.getStat();
    cout << "\n┌──────────── 현재 스탯 ───────────────────────────────────┐" << endl;
    cout << "│ 매력: " << s.getCharm()
        << "  지능: " << s.getIntelligence()
        << "  체력: " << s.getStrength()
        << "  예술: " << s.getArt()
        << "  스트레스: " << s.getStress()
        << "  재화: " << s.getMoney() << " │" << endl;
    cout << "└──────────────────────────────────────────────────────────┘" << endl;
}

// ------------------------- ActionFactory -------------------------
class ActionFactory {
public:
    struct ActionInfo {
        string name;
        Stat stat;
    };

    static unique_ptr<Act> create(ActCategory category, int option, const Stat& currentStat);
};

// ------------------------- 행동 테이블 -------------------------
const map<pair<ActCategory, int>, ActionFactory::ActionInfo> actionTable = {
    {{ActCategory::Charm, 1}, {"씻기",         Stat().addCharm(1).addStress(1).addMoney(-1)}},
    {{ActCategory::Charm, 2}, {"미용실 가기",  Stat().addCharm(2).addStress(2).addMoney(-2)}},
    {{ActCategory::Charm, 3}, {"피부과 가기",  Stat().addCharm(3).addStress(3).addMoney(-3)}},

    {{ActCategory::Intelligence, 1}, {"공부하기",   Stat().addIntelligence(1).addStress(1).addMoney(-1)}},
    {{ActCategory::Intelligence, 2}, {"학원 가기",   Stat().addIntelligence(2).addStress(2).addMoney(-2)}},
    {{ActCategory::Intelligence, 3}, {"과외 받기",   Stat().addIntelligence(3).addStress(3).addMoney(-3)}},

    {{ActCategory::Strength, 1}, {"상명대 언덕 오르기", Stat().addStrength(1).addStress(1).addMoney(-1)}},
    {{ActCategory::Strength, 2}, {"헬스장 가기",      Stat().addStrength(2).addStress(2).addMoney(-2)}},
    {{ActCategory::Strength, 3}, {"PT 받기",         Stat().addStrength(3).addStress(3).addMoney(-3)}},

    {{ActCategory::Art, 1}, {"종이접기",      Stat().addArt(1).addStress(1).addMoney(-1)}},
    {{ActCategory::Art, 2}, {"전시회 보러가기", Stat().addArt(2).addStress(2).addMoney(-2)}},
    {{ActCategory::Art, 3}, {"그림 그리기",    Stat().addArt(3).addStress(3).addMoney(-3)}},

    {{ActCategory::Rest, 1}, {"집에서 쉬기", Stat().addStress(-1).addMoney(-1)}},
    {{ActCategory::Rest, 2}, {"맛집 탐방",    Stat().addStress(-2).addMoney(-2)}},
    {{ActCategory::Rest, 3}, {"바캉스",       Stat().addStress(-3).addMoney(-3)}},

    {{ActCategory::Work, 1}, {"전단지 돌리기",    Stat().addStress(1).addMoney(1)}},
    {{ActCategory::Work, 2}, {"편의점 아르바이트", Stat().addStress(2).addMoney(2)}},
    {{ActCategory::Work, 3}, {"쿠팡 상하차",     Stat().addStress(3).addMoney(3)}},
};

// ------------------------- ActionFactory::create 구현 -------------------------
unique_ptr<Act> ActionFactory::create(ActCategory category, int option, const Stat& currentStat) {
    auto it = actionTable.find({ category, option });
    if (it == actionTable.end()) {
        struct UnknownAct : public Act {
            string getName() const override { return "알 수 없는 행동"; }
            Stat getStatEffect() const override { return {}; }
        };
        return make_unique<UnknownAct>();
    }

    const ActionInfo& info = it->second;
    int moneyChange = info.stat.getMoney();

    if (moneyChange < 0 && currentStat.getMoney() + moneyChange < 0) {
        cout << "재화가 부족합니다" << endl;
        return nullptr;
    }

    class CustomAct : public Act {
        string name;
        Stat effect;
    public:
        CustomAct(const string& n, const Stat& s) : name(n), effect(s) {}
        string getName() const override { return name; }
        Stat getStatEffect() const override { return effect; }
    };

    return make_unique<CustomAct>(info.name, info.stat);
}

// ------------------------- main -------------------------
int main() {
    Character player("홍길동");

    cout << "게임을 시작합니다.\n";

    for (int turn = 1; turn <= 12; ++turn) {
        cout << "\n===== " << turn << "번째 턴 =====" << endl;

        for (int i = 1; i <= 5; ++i) {
            cout << "\n[행동 " << i << "/5]\n";

            while (true) {
                printStatBox(player);  // 행동 시작 시에만 출력

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

                ActCategory category;
                switch (categoryInput) {
                case 1: category = ActCategory::Charm; break;
                case 2: category = ActCategory::Intelligence; break;
                case 3: category = ActCategory::Strength; break;
                case 4: category = ActCategory::Art; break;
                case 5: category = ActCategory::Rest; break;
                case 6: category = ActCategory::Work; break;
                default:
                    cout << "잘못된 입력입니다. 다시 입력해주세요.\n";
                    continue;
                }

                cout << "\n선택할 수 있는 행동들:\n";
                cout << "1. 1티어 \n";
                cout << "2. 2티어\n";
                cout << "3. 3티어\n";

                int option;
                cout << "\n행동 번호를 입력하세요: ";
                cin >> option;

                unique_ptr<Act> act = ActionFactory::create(category, option, player.getStat());

                if (act) {
                    cout << "\n선택한 행동: " << act->getName() << endl;
                    player.applyAct(*act);
                    break;  // 성공 시 루프 탈출
                }
                else {
                    cout << "\n행동을 수행할 수 없습니다. 다시 선택해주세요.\n";
                }
            }
        }
    }

    cout << "\n====== 게임 종료 ======\n";
    printStatBox(player);
    cout << "\n최종 엔딩: " << determineEnding(player.getStat()) << endl;

    return 0;
}
