#include <iostream>
#include <test/tools.h>

using namespace std;

void pair_main()
{
    pair<string, int> pa("Jmc", 5);
    tools::print({pa.first});
    tools::print({pa.second});

    auto pa2 = make_pair("Anne", 6);
    tools::print({pa2.first});
    tools::print({pa2.second});
}






