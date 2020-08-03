#include <iostream>
#include "tools.h"

using namespace std;

//很多类的初始化都是用这个初始化列表作为参数，可以接收不定参数
//{elements}会被编译器直接当成initializer_list
void print(initializer_list<int> l)
{
    for (auto i : l) cout << i << '\t';
    cout << endl;
}

class add
{
    public:
        add(int a, int b)
        {
            cout << "默认构造："
                     << a + b << endl;
        }
        
        add(initializer_list<int> l)
        {
            int result = 0;
            for (int i : l) result += i;
            
            cout << "可变参数构造："
                     << result << endl;
        }
};

void init_list_main()
{
    print({1, 2, 3, 4, 5});
    add(3, 4);
    add({3, 4});
    add({1, 2, 3, 4, 5});
    //很多函数支持可变参数了
    cout << max({1, 2, 3, 4, 5}) << endl;
    cout << "-----------------------------------------------";
    
    //auto&不管元素多大，拿出的都
    //是指针，只占4个字节，省内存
    //但要小心：这样可以修改
    //数组内部数据(可以用const包装)
    for (const auto& i : {1, 3, 5, 7, 9})
        cout << i << '\t';
    cout << endl;
    
    
}
