#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <array>
#include <functional>
#include <numeric>
#include <fstream>
#include <sstream>
#include <cmath>
#include <thread>

#include "file.h"

#define len(x) sizeof(x) / sizeof(x[0])

using namespace std; 

//ģ�庯������д��.cpp������Ӳ���
/*
clock()
�������Է����Գ���ʼִ�е���ǰλ��Ϊֹ, �������߹���ʱ�Ӵ����
*/
template<class Func>
void timer(Func func, string msg)
{
    typedef clock_t ct;
    ct start = clock();
    func();
    ct end = clock();
    cout << msg
        << "��ʱ"
        //Linux clock()����ֵ����ms��������Ҫ��ת��Ϊ���ٳ�1000
        << (double)(end - start) / CLOCKS_PER_SEC * 1000
        << "ms\n"
        << endl;
}

template<class T>
void print_a(const T a, int len)
{
    cout << "[ ";
    for (int i = 0; i < len; i++)
        cout << a[i] << ", ";
    cout << "\b\b ]" << endl;
}

template<class T>
void print_a(T t)
{
    cout << "[ ";
    for (auto it = t.begin(); it != t.end(); ++it)
        cout << *it << ", ";
    cout << "\b\b ]" << endl;
}

template<class T>
void print_m(T t)
{
    if (t.empty())
    {
        cout << "{ }" << endl;
        return;
    }
    cout << "{ ";
    for (auto it = t.begin(); it != t.end(); ++it)
        cout << it->first << "=" << it->second << ", ";
    cout << "\b\b }" << endl;
}

template<class T>
void sort(T a, int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int k = 0; k < len - 1 - i; k++)
            if (a[k] > a[k + 1])
                swap(a[k], a[k + 1]);
}

void out_sth();

template<class T, class... Ts>
void out_sth(T t, Ts... ts)
{
    cout << t << '\t';
    out_sth(ts...);
}

void out_sth_endl();

template<class T, class... Ts>
void out_sth_endl(T t, Ts... ts)
{
    cout << t << "\n";
    out_sth(ts...);
}

