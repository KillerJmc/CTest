#include <iostream>
#include "tools.h"

using namespace std;

void typedef_main()
{
    //typedef即类型的别名
    typedef string str;
    str s = "Hello World!";
    cout << s << endl;
    
    //unsigned int也有自己的别名
    size_t i = -3;
    cout << i << endl;
    
    i = 3;
    cout << i << endl;
    

}

