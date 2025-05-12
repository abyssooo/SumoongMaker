#pragma once

#include <map>
#include <string>
#include "Act.h"
#include "Stat.h"

using namespace std;

class ActionFactory {
public:
    struct ActionInfo {
        string name;
        Stat stat;
    };

    static unique_ptr<Act> create(ActCategory category, int option);
};

