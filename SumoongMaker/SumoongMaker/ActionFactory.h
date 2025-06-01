#pragma once

#include <map>
#include <string>
#include "Act.h"
#include "Stat.h"
#include <vector>


using namespace std;

class ActionFactory {
public:
    struct ActionInfo {
        string name;
        Stat stat;
    };

    static unique_ptr<Act> create(ActCategory category, int option);
    static vector<string> getActionNames(ActCategory category);
};

