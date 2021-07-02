#include <iostream>

using namespace std;

/**
    指针的申请与释放
*/
void ptr_main()
{
    int * p1 = new int;
    int * p2 = (int *)malloc(sizeof(int));
    //删除的是内存内容
    delete p1;
    free(p2);  
    //赋值为NULL才能重复删除，理由在上
    p1 = NULL;
    p2 = NULL;
}