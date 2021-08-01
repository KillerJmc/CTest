#include <iostream>
#include <map>
#include <tools>

using namespace std;

class Comparator
{
    public:
        bool operator()(int i, int k) const
        {
            return i > k;
        }
};

void map_test01()
{
    //自动排序key不可重复
    map<string, int> m;
    for (int i = 0; i < 5; i++)
        m.insert(make_pair("Jmc", i + 1));
    tools::print_map(m);
    
    //自动排序，key可重复
    multimap<string, int> m2;
    for (int i = 0; i < 5; i++)
        m2.insert(make_pair("Jmc", i + 1));
    tools::print_map(m2);
   
    //通过key删除
    m2.erase("Jmc");
    tools::print_map(m2);
    
}

void map_test02()
{
    map<int, int, less<int>> m;
    for (int i = 10; i <= 50; i += 10)
        m.insert(make_pair(i / 10, i));
    tools::print_map(m);
    
    //map<int, int, Comparator> m2;
    map<int, int, greater<int>> m2;
    for (int i = 10; i <= 50; i += 10)
        m2.insert(make_pair(i / 10, i));
    tools::print_map(m2);
    
}

void map_test03()
{
    multimap<int, int> m;
    for (int i = 10; i <= 100; i+= 10)
        m.insert(make_pair(i % 3, i));
    tools::print_map(m);
    
    cout << "key为1的有：" << endl;
    int count = m.count(1);
    auto begin = m.find(1);
    auto end = m.find(1);
    for (int i = 0; i < count; ++i) end++;
    m.erase(m.begin(), begin);
    m.erase(end, m.end());
    tools::print_map(m);
    
}

void map_main()
{
    map_test03();
}




