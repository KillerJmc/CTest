#include <iostream>
#include "tools.h"

using namespace std;

void rand_main()
{ 
    //srand������������
    //����
    srand(time(NULL));
    int a[10];
    //���10��100��200����
    for (int i : a) cout << rand() % 101 + 100 << ", ";
    
}
