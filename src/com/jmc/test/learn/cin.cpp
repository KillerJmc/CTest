#include <iostream>
#include "tools.h"
#include <cstdio>

using namespace std;

void cin_main()   
{
    /*
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    */
    int i;
    char c1, c2, c3;
    //可输入123abc
    cin >> i >> c1 >> c2 >> c3;
    //这里用printf更简洁
    printf("%d\t%c\t%c\t%c\t", i, c1, c2, c3);
    

    
    
    
    
}

