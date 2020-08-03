#include <iostream>
#include "tools.h"

using namespace std;

void lambda_test01()
{
    //不调用
    [] {};
    
    //直接调用自身
    [] {
        cout << "Hello World!" << endl;
    }();
    
    //间接调用
    auto l1 = [] {
        cout << "what?" << endl;
    };
    l1();
    cout << typeid(l1).name() << endl;
}

/*中括号真正内涵：以auto l1做示范
auto l1相当于：
class l1
{
    private:
        int _a;(read_only)
        int _b;(read_only)
    public:
        l1(int a, int b): _a(a), _b(b) {}
        auto operator()() {}
};
*/
void lambda_test02()
{
    int a = 3, b = 4;
    //传入的a, b均为只读
    auto l1 = [a, b]() {
        //只读对象不可修改！
        //a++;
    };
    
    //mutable：声明可修改
    auto l2 = [a, b]() mutable {
        //可修改
        a++;
    };
    
    //引用当然可修改
    auto l3 = [&a, b]() {
        a++;
        //b为值传递不能修改
        //b++;
    };
    
    //声明返回类型，
    //可避免写代码出错
    auto l4 = []() -> string {
        return "";
    };
    
}

void lambda_main()
{
    lambda_test02();
}
