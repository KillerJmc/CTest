#include <iostream>
#include "tools.h"

using namespace std;

class A 
{
    public:
        //静态常量可以在类中声明
        const static int c_i = 8;
        //普通静态变量必须在类外声明
        static int i;
        static void main(string args[])
        {
            //静态方法可使用静态变量
            i = 6;
            cout << args[1] << endl;
        }
};

//初始化类静态变量
int A::i = 3;

void static_main()
{ 
    cout << A::c_i << endl;
    //或者A a; cout << a.i;
    cout << A::i << endl; 
    
    string args[] {"0", "666"};
    //或者A a; a.main(args);
    A::main(args);
    cout << A::i;
    
}




