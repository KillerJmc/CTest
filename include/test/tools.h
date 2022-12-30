#pragma once

#include <iostream>
#include <chrono>

namespace tools {
    template<class Func> size_t timer(Func func)
    {
        typedef std::chrono::high_resolution_clock clock;
        using std::chrono::milliseconds;

        auto start = clock::now();
        func();
        auto end = clock::now();

        milliseconds m = std::chrono::duration_cast<milliseconds>(end - start);

        // ms
        return m.count();
    }

    template<class Func> void timer(Func func, const std::string& msg)
    {
        std::cout << msg
            << "耗时"
            << tools::timer(func)
            << "ms\n"
            << std::endl;
    }

    template<class Arr> int len(Arr& a)
    {
        return sizeof(a) / sizeof(a[0]);
    }

    template<class Arr> void print_arr(const Arr a, int len)
    {
        std::cout << "[ ";
        for (int i = 0; i < len; i++)
            std::cout << a[i] << ", ";
        std::cout << "\b\b ]" << std::endl;
    }

    template<class Sequence> void print_stl(Sequence s)
    {
        std::cout << "[ ";
        for (auto it = s.begin(); it != s.end(); ++it)
            std::cout << *it << ", ";
        std::cout << "\b\b ]" << std::endl;
    }

    template<class Map> void print_map(Map m)
    {
        if (m.empty())
        {
            std::cout << "{ }" << std::endl;
            return;
        }
        std::cout << "{ ";
        for (auto it = m.begin(); it != m.end(); ++it)
            std::cout << it->first << "=" << it->second << ", ";
        std::cout << "\b\b }" << std::endl;
    }

    template<class T> void print(std::initializer_list<T> list)
    {
        for (const auto& t : list)
            std::cout << t << std::endl;
    }
}

