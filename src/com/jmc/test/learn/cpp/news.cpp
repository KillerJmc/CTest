#include <iostream>
#include "tools.h"

using namespace std;

void news_main()   
{
    int * p_i = new int;
    *p_i = 3;
    cout << *p_i << endl;
    delete p_i;
}

