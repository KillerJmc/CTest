#include <iostream>
#include <test/tools.h>

using namespace std;

void string2_test01()
{ 
    string s = "abcde abcde";
    int idx1 = s.find("c");
    //反向寻找
    int idx2 = s.rfind("c");
    
    int idx3 = s.find("h");
 
    tools::print({idx1, idx2, idx3});
    
    //范围替换
    s.replace(1, 3, "!!!oksir!!!");
    cout << s << endl;   
    
    cout << "-----------------------------------------------";
}

void string2_test02()
{
    string s1 = "hello";
    string s2 = "hello";
    
    cout << s1.compare(s2) << endl;
    s2 = "kello";
    cout << s1.compare(s2) << endl;
    s2 = "aello";
    cout << s1.compare(s2) << endl;
    
    cout << "-----------------------------------------------";
}

void string2_test03()
{
    string s = "hello";
    s[0] = 'p';
    s.at(3) = 'u';
    cout << s << endl;
    cout << "-----------------------------------------------";
}

void string2_test04()
{
    string s = "hello";
    string s2 = "papapa";
    s.insert(3, s2);
    cout << s << endl;
    s.erase(3, s2.size());
    cout << s << endl;
    cout << "-----------------------------------------------";
}

void string2_test05()
{
    string s1 = "hello@qq.com";
    //从2位置开始，截取一个长度
    //为1的字符串
    string s2 = s1.substr(2, 1);
    cout << s2 << endl;
    
    //从0位置开始截取
    string s3 = s1.substr(0, s1.find("@"));
    cout << s3 << endl;
    
}

void string2_main()
{
    string2_test01();
    string2_test02();
    string2_test03();
    string2_test04();
    string2_test05();
    
}

