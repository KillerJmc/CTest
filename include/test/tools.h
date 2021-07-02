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
static bool has_rand_seed = false;

using namespace std; 

template<class Func>
size_t timer(Func func)
{
    typedef std::chrono::high_resolution_clock clock;
    using std::chrono::milliseconds;

    auto start = clock::now();
    func();
    auto end = clock::now();

    milliseconds m = chrono::duration_cast<milliseconds>(end - start);
    return m.count();
}

template<class Func>
void timer(Func func, const string& msg)
{
    cout << msg
        << "耗时"
        << timer(func)
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

template<class Map>
void print_m(Map m)
{
    if (m.empty())
    {
        cout << "{ }" << endl;
        return;
    }
    cout << "{ ";
    for (auto it = m.begin(); it != m.end(); ++it)
        cout << it -> first << "=" << it -> second << ", ";
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

int rand(int start, int end);

int rand(int end);
