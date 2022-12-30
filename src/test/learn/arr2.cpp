#include <iostream>
#include <test/tools.h>

using namespace std;

void sort(int *, int);
void reverse(int *, int);

void arr2_main()   
{
    int a[] = { 12, 15, 7, 0, 8, 5, 4, 1, 20, -3, 6 };
    sort(a, tools::len(a));
    tools::print_arr(a, tools::len(a));
    reverse(a, tools::len(a));
    tools::print_arr(a, tools::len(a));

}

//冒泡排序（让最小值不断冒到最顶端）
void sort(int * a, int len) 
{
    //只需循环数组长度-1次
    for (int k = 0; k < len - 1; k++)
        //从末尾开始循环
        for (int i = len - 1; i > k; i--)
            //如果后一个值小于前一个
            if (a[i] < a[i - 1])
                //交换(和冒泡一样冒上去)
                swap(a[i], a[i - 1]);
}

void reverse(int * a, int len)
{
    for (int i = 0; i < len / 2; i++)
        swap(a[i], a[len - 1 - i]);
}

