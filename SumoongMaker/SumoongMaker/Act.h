#pragma once

#include<iostream>
#include <string>
#include "Stat.h"

using namespace std;

enum class ActCategory { Art, Charm, Intelligence, Strength, Rest, Work };

class Act {
public:
    virtual ~Act() = default;
    virtual string getName() const = 0;
    virtual Stat getStatEffect() const = 0;
};
