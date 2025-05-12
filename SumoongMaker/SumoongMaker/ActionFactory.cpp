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
    // �ŷ�
    {{ActCategory::Charm, 1}, {"�ı�",         Stat().addCharm(1)
                                              .addStress(1)
                                              .addMoney(-1)}},
    {{ActCategory::Charm, 2}, {"�̿�� ����",  Stat().addCharm(2)
                                              .addStress(2)
                                              .addMoney(-2)}},
    {{ActCategory::Charm, 3}, {"�Ǻΰ� ����",  Stat().addCharm(3)
                                              .addStress(3)
                                              .addMoney(-3)}},

    // ����
    {{ActCategory::Intelligence, 1}, {"�����ϱ�",   Stat().addIntelligence(1)
                                                          .addStress(1)
                                                          .addMoney(-1)}},
    {{ActCategory::Intelligence, 2}, {"�п� ����",   Stat().addIntelligence(2)
                                                           .addStress(2)
                                                           .addMoney(-2)}},
    {{ActCategory::Intelligence, 3}, {"���� �ޱ�",   Stat().addIntelligence(3)
                                                           .addStress(3)
                                                           .addMoney(-3)}},

    // ü��
    {{ActCategory::Strength, 1}, {"���� ��� ������", Stat().addStrength(1)
                                                              .addStress(1)
                                                              .addMoney(-1)}},
    {{ActCategory::Strength, 2}, {"�ｺ�� ����",      Stat().addStrength(2)
                                                            .addStress(2)
                                                            .addMoney(-2)}},
    {{ActCategory::Strength, 3}, {"PT �ޱ�",        Stat().addStrength(3)
                                                          .addStress(3)
                                                          .addMoney(-3)}},

    // ����
    {{ActCategory::Art, 1}, {"��������",      Stat().addArt(1)
                                                    .addStress(1)
                                                    .addMoney(-1)}},
    {{ActCategory::Art, 2}, {"����ȸ ��������", Stat().addArt(2)
                                                      .addStress(2)
                                                      .addMoney(-2)}},
    {{ActCategory::Art, 3}, {"�׸� �׸���",    Stat().addArt(3)
                                                     .addStress(3)
                                                     .addMoney(-3)}},

    // �޽�
    {{ActCategory::Rest, 1}, {"������ ����", Stat().addStress(-1)
                                                   .addMoney(-1)}},
    {{ActCategory::Rest, 2}, {"���� Ž��",    Stat().addStress(-2)
                                                    .addMoney(-2)}},
    {{ActCategory::Rest, 3}, {"��Ĳ��",       Stat().addStress(-3)
                                                    .addMoney(-3)}},

    // �Ƹ�����Ʈ
    {{ActCategory::Work, 1}, {"������ ������",    Stat().addStress(1)
                                                        .addMoney(1)}},
    {{ActCategory::Work, 2}, {"������ �Ƹ�����Ʈ", Stat().addStress(2)
                                                         .addMoney(2)}},
    {{ActCategory::Work, 3}, {"���� ������",     Stat().addStress(3)
                                                       .addMoney(3)}},
};


unique_ptr<Act> ActionFactory::create(ActCategory category, int option) {
    auto it = actionTable.find({ category, option });
    if (it == actionTable.end()) {
        struct UnknownAct : public Act {
            string getName() const override { return "�� �� ���� �ൿ"; }
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
