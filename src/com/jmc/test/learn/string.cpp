#include <iostream>
#include "../main/tools.h"

using namespace std;

void string_main()
{ 
    string s1(10, 'a');
    cout << s1 << endl;
    
    const char * cs = "Hello C++";
    //把c_string转化为c++_string
    string s2(cs);
    cout << s2 << endl;
    
    string s3(s2);
    cout << s3 << endl;
    
    string s4;
    s4.assign("Hello C++", 5);
    cout << s4 << endl;
    
    //以10个n组成的字符串
    s4.assign(10, 'n');
    cout << s4 << endl;
    
    cout << "-----------------------------------------------";
    
    string a = "I";
    //追加某个字符串前5个字符
    a.append(" lovehahaha", 5);
    //追加某字符串从第4个索引
    //（第5个字符）
    //开始的连续4个之后字符
    a.append("haah yousjkk", 4, 4);
    //直接末尾追加
    a.append("!");
    
    cout << a << endl;
    
}
