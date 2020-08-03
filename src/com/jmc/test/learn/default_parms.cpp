#include <iostream>
#include "tools.h"

using namespace std;

//在函数原型中写默认参数
//从右到左读取默认参数，不能间断
void get(int = 3, int = 4, int = 5);

void default_parms_main()
{
    get(1);
}

void get(int a, int b, int c)
{
    printf("%d    %d    %d", a, b, c);
}

