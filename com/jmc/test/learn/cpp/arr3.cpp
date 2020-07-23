#include <iostream>
#include "tools.h"

#define len(x) sizeof(x) / sizeof(x[0])

using namespace std;

void print_arr(const int a[], int len)
{
    cout << "[ ";
    for (int i = 0; i < len; i++)
        cout << a[i] << ", ";
    cout << "\b\b ]" << endl;
}

void sort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int k = 0; k < len - 1 - i; k++)
            if (a[k] > a[k + 1])
                swap(a[k], a[k + 1]);
}

//Cָ��д��
void add(int ** a, int * len, int t)
{
    int * temp = new int[*len + 1];
    
    for (int i = 0; i < *len; i++)
        //С�ģ�����д�� temp[k] = *a[k]
        //�ᱨ���Ҳ�֪�������������
        //(*a)[i]Ҳ�� 
        temp[i] = *(*a + i);
    temp[*len] = t;
    
    delete[] *a;
    *a = temp;
    (*len)++;
    sort(*a, *len);
}

//C++����д��
void remove(int * & a, int & len, int t)
{
    int * temp = new int[len - 1];
    bool exist = false;
    
    for (int i = 0; i < len; i++)
    {
        if (a[i] == t) 
        {
            a[i] = INT_MAX;
            exist = true;
            sort(a, len);
        }
    }
        
    if (!exist)
    {
        cout << "������Ԫ��" << t << endl;
        return;
    }
    
    for (int i = 0; i < len - 1; i++)
        temp[i] = a[i];
    
    delete[] a;
    a = temp;
    len--;
}

void arr3_main()   
{
    int len = 5;
    int * a = new int[len] {5, 0, 4, 10, 8};
    print_arr(a, len);
    
    add(&a, &len, 6);
    print_arr(a, len);
    
    remove(a, len, 4);
    print_arr(a, len);
    
    delete[] a;
    a = NULL;

}

