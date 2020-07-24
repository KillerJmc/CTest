#include <iostream>
#include "tools.h"

using namespace std;

void pair_main()
{
    pair<string, int> pa("Jmc", 5);
    out_sth_endl(pa.first, pa.second);
    
    auto pa2 = make_pair("Anne", 6);
    out_sth_endl(pa2.first, pa2.second);
}






