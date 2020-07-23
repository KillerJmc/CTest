#include <iostream>
#include "tools.h"

using namespace std;

#define len(x) sizeof(x) / sizeof(x[0])

void sort(int *, int);
void print_arr(int *, int);
void reverse(int *, int);

void arr2_main()   
{
    int a[] = { 12, 15, 7, 0, 8, 5, 4, 1, 20, -3, 6 };
    sort(a, len(a));
    print_arr(a, len(a));
    reverse(a, len(a));
    print_arr(a, len(a));

}

//ð����������Сֵ����ð����ˣ�
void sort(int * a, int len) 
{
    //ֻ��ѭ�����鳤��-1��
    for (int k = 0; k < len - 1; k++)
        //��ĩβ��ʼѭ��
        for (int i = len - 1; i > k; i--)
            //�����һ��ֵС��ǰһ��
            if (a[i] < a[i - 1])
                //����(��ð��һ��ð��ȥ)
                swap(a[i], a[i - 1]);
}

void reverse(int * a, int len)
{
    for (int i = 0; i < len / 2; i++)
        swap(a[i], a[len - 1 - i]);
}

void print_arr(int * a, int len)
{
    cout << "[ ";
    for(int i = 0; i < len; i++)
        cout << a[i] << ", ";
    cout << "\b\b ]" << endl;
}

