#pragma once

#include <iostream>
#include <test/tools.h>

using namespace std;

namespace cannon {
    class Cannon
    {
    private:
        bool canShoot = false;
        const int SCENE_SIZE = 100;
        const int HIT_RANGE = 5;

    public:
        void load_bullets();
        void fire();
        bool win = false;
    };

    void start_cannon();
}
