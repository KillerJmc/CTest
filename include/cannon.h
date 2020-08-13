#pragma once

#include <iostream>
#include "tools.h"

using namespace std;

class Cannon
{
private:
    bool canShoot = false;
    const int SCENE_SIZE = 20;
    const int HIT_RANGE = 5;

public:
    void load_bullets();
    void fire();
    bool win = false;
};

static void start();
