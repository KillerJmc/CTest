#include "tools.h"

void out_sth()
{
}

void out_sth_endl()
{
}

int rand(int start, int end) {
    if (!has_rand_seed)
    {
        srand(time(nullptr));
        has_rand_seed = true;
    }
    return rand() % (end - start + 1) + start;
}

int rand(int end) {
    return rand(0, end);
}
