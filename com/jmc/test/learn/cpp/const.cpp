#include <iostream>
#include "tools.h"

using namespace std;

class A 
{
    //给隐含的this指针参数加const
    int get() const;
    public: 
        //使得只能用const接收返回值
        const int & get1(int & i) {return i;}
};

void const_main()
{ 
    int num1 = 0;
    
    //const在*左侧：不能修改值
    const int * p_1 = &num1;
    //*p_1 = 1;
    p_1 = nullptr;
    
    //与p_1相同
    int const * p_2 = &num1;
    //*p_2 = 2;
    p_2 = nullptr;
    
    //const在*右侧：
    //不能修改指针变量
    int * const p_3 = &num1;
    *p_3 = 3;
    //p_3 = nullptr;
    
    //相当于int const * const p_4;
    const int * const p_4 = &num1;
    //*p_4 = 4;
    //p_4 = nullptr;
    
    A a;
    //一定要加const接受
    const int & r_i = a.get1(num1);
    
    
    
}


