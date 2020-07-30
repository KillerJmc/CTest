#include <iostream>
#include "../main/tools.h"

using namespace std;

typedef string s;

class Bases {
    public:
        s p1 = "public";
        static int sta;
    protected:
        s p2 = "protected";
    private:
        s p3 = "private";
};

int Bases::sta = 3;

//公共继承，保护基础，私有继承

//可访问父类public, protected, static 内容
//权限不变
//继承所有非静态成员
//私有属性被编译器隐藏无法访问
class Aa : public Bases {
    public:
        static int sta;
};

int Aa::sta = 10;

//将父类public, protected, static内容转换为
//protected内容储存
class B : protected Bases{};

//将父类public, portected, static内容转化为
//private内容储存
class C : private Bases{};

class What : public Aa, protected B, private C{};

void extends_main()
{ 
    Aa a; B b; C c;
    //注意：如果子类中有与父类同名的函数等，父类关于此函数的所有函数会被编译器隐藏（因此以后默认调用子类该函数，即使父类有重载函数也访问不了），需要用作用域调用该函数，而属性则默认调子类的属性，也可用加作用域以访问父类属性
    
    cout << a.sta << endl;
    //访问父类的属性要加作用域
    //表示访问a下Bases作用域
    //下的sta属性
    cout << a.Bases::sta << endl;
    cout << Aa::sta << endl;
              //通过类名方式访问，通过父类作用域访问
    cout << Aa::Bases::sta << endl;
}
