#include <iostream>
#include "tools.h"
#include <iomanip>

using namespace std;

void fixed_main()   
{
    //�̶�����Ϊ6
    cout << fixed;
    //���þ���Ϊ2(��Ҫ����)
    //cout << fixed << setprecision(2);
    cout << 10 / 3.0 * 1000000;

}

