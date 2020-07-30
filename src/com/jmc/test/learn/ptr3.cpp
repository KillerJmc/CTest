#include <iostream>
#include "../main/tools.h"

using namespace std;

int get3();
int get5();
void show(int (*)());

void ptr3_main()
{
    //普通写法
    int (*get)();

    //用typedef
    /*
    typedef int (*getTemplate)(); 
    getTemplate get;
    */

    //用c++auto(相当于java10的var)
    //auto get0 = get3;
    cout << "get what?" << endl;
    
    int i;
/*   不能用cin.get()，它等价于getchar()
用于获取单个字符（无参数时）！！！
*/
    cin >> i;
    get = (i == 3 ? get3 : i == 5 ? get5 : NULL);
    if (get == NULL) cout << "Invalid!" << endl;
    show(get);
}

void show(int (*get)())
{
    cout << "\n" << get() << endl;
}

int get3()
{
    return 3;
}

int get5()
{
    return 5;
}
