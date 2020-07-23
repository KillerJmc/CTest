#include <iostream>
#include "tools.h"

using namespace std;

void rand_main()
{ 
    //srand方法设置种子
    //或者
    srand(time(NULL));
    int a[10];
    //输出10个100到200的数
    for (int i : a) cout << rand() % 101 + 100 << ", ";
    
}
