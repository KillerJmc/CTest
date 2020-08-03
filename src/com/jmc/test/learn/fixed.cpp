#include <iostream>
#include "tools.h"
#include <iomanip>

using namespace std;

void fixed_main()   
{
    //固定精度为6
    cout << fixed;
    //设置精度为2(需要导库)
    //cout << fixed << setprecision(2);
    cout << 10 / 3.0 * 1000000;

}

