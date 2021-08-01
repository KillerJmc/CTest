#include <iostream>
#include <list>
#include <tools>

using namespace std;

bool comparator(int v1, int v2)
{
    //降序
    return v1 > v2; 
}

void list_main()
{
    //双向链表
    list<int> l;
    for (int i = 0; i < 5; i++)
    {
        l.push_front((i + 1) * 10);
        l.push_back((i + 1) * 10);
    }

    tools::print_stl(l);
    //移除所有与40相关的元素
    l.remove(40);
    tools::print_stl(l);
    cout << "-----------------------------------------------";
    
    l.clear();
    for (int i = 0; i < 5; i++)
        l.push_front((i + 1) * 10);
    tools::print_stl(l);
    l.reverse();
    tools::print_stl(l);
    //l.sort();
    l.sort(comparator);
    tools::print_stl(l);
   
}
