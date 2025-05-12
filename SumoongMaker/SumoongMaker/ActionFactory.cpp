#pragma once

#include "ActionFactory.h"
#include "Act.h"
#include "Stat.h"

#include <map> 
#include <functional>
#include <memory>
#include <utility>

using namespace std;
using ActionInfo = ActionFactory::ActionInfo;


const map<pair<ActCategory, int>, ActionInfo> actionTable = {
    // 매력
    {{ActCategory::Charm, 1}, {"씻기",         Stat().addCharm(1)
                                              .addStress(1)
                                              .addMoney(-1)}},
    {{ActCategory::Charm, 2}, {"미용실 가기",  Stat().addCharm(2)
                                              .addStress(2)
                                              .addMoney(-2)}},
    {{ActCategory::Charm, 3}, {"피부과 가기",  Stat().addCharm(3)
                                              .addStress(3)
                                              .addMoney(-3)}},

    // 지능
    {{ActCategory::Intelligence, 1}, {"공부하기",   Stat().addIntelligence(1)
                                                          .addStress(1)
                                                          .addMoney(-1)}},
    {{ActCategory::Intelligence, 2}, {"학원 가기",   Stat().addIntelligence(2)
                                                           .addStress(2)
                                                           .addMoney(-2)}},
    {{ActCategory::Intelligence, 3}, {"과외 받기",   Stat().addIntelligence(3)
                                                           .addStress(3)
                                                           .addMoney(-3)}},

    // 체력
    {{ActCategory::Strength, 1}, {"상명대 언덕 오르기", Stat().addStrength(1)
                                                              .addStress(1)
                                                              .addMoney(-1)}},
    {{ActCategory::Strength, 2}, {"헬스장 가기",      Stat().addStrength(2)
                                                            .addStress(2)
                                                            .addMoney(-2)}},
    {{ActCategory::Strength, 3}, {"PT 받기",        Stat().addStrength(3)
                                                          .addStress(3)
                                                          .addMoney(-3)}},

    // 예술
    {{ActCategory::Art, 1}, {"종이접기",      Stat().addArt(1)
                                                    .addStress(1)
                                                    .addMoney(-1)}},
    {{ActCategory::Art, 2}, {"전시회 보러가기", Stat().addArt(2)
                                                      .addStress(2)
                                                      .addMoney(-2)}},
    {{ActCategory::Art, 3}, {"그림 그리기",    Stat().addArt(3)
                                                     .addStress(3)
                                                     .addMoney(-3)}},

    // 휴식
    {{ActCategory::Rest, 1}, {"집에서 쉬기", Stat().addStress(-1)
                                                   .addMoney(-1)}},
    {{ActCategory::Rest, 2}, {"맛집 탐방",    Stat().addStress(-2)
                                                    .addMoney(-2)}},
    {{ActCategory::Rest, 3}, {"바캉스",       Stat().addStress(-3)
                                                    .addMoney(-3)}},

    // 아르바이트
    {{ActCategory::Work, 1}, {"전단지 돌리기",    Stat().addStress(1)
                                                        .addMoney(1)}},
    {{ActCategory::Work, 2}, {"편의점 아르바이트", Stat().addStress(2)
                                                         .addMoney(2)}},
    {{ActCategory::Work, 3}, {"쿠팡 상하차",     Stat().addStress(3)
                                                       .addMoney(3)}},
};


unique_ptr<Act> ActionFactory::create(ActCategory category, int option) {
    auto it = actionTable.find({ category, option });
    if (it == actionTable.end()) {
        struct UnknownAct : public Act {
            string getName() const override { return "알 수 없는 행동"; }
            Stat getStatEffect() const override { return {}; }
        };
        return make_unique<UnknownAct>();
    }
    const ActionInfo& info = it->second;

    class CustomAct : public Act {
        string name;
        Stat effect;
    public:
        CustomAct(const string& n, const Stat& s)
            : name(n), effect(s) {
        }

        string getName() const override { return name; }
        Stat getStatEffect() const override { return effect; }
    };

    return make_unique<CustomAct>(info.name, info.stat);
}
