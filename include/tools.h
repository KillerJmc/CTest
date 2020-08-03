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
#include <cstring>

#include "file.h"

#define len(x) sizeof(x) / sizeof(x[0])

using namespace std; 

//模板函数不能写在.cpp里，会链接不到
/*
clock()
函数可以返回自程序开始执行到当前位置为止, 处理器走过的时钟打点数
*/
template<class Func>
void timer(Func func, string msg)
{
    typedef clock_t ct;
    ct start = clock();
    func();
    ct end = clock();
    cout << msg
        << "耗时"
        //Linux clock()返回值不是ms，所以需要先转化为秒再乘1000
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

