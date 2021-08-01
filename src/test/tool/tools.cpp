#include <tools.h>

int tools::rand(int start, int end) {
    static bool has_rand_seed = false;
    if (!has_rand_seed)
    {
        std::srand(time(nullptr));
        has_rand_seed = true;
    }
    return std::rand() % (end - start + 1) + start;
}
