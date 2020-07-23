#include <iostream>
#include "tools.h"

using namespace std;

void lambda_test01()
{
    //������
    [] {};
    
    //ֱ�ӵ�������
    [] {
        cout << "Hello World!" << endl;
    }();
    
    //��ӵ���
    auto l1 = [] {
        cout << "what?" << endl;
    };
    l1();
    cout << typeid(l1).name() << endl;
}

/*�����������ں�����auto l1��ʾ��
auto l1�൱�ڣ�
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
    //�����a, b��Ϊֻ��
    auto l1 = [a, b]() {
        //ֻ�����󲻿��޸ģ�
        //a++;
    };
    
    //mutable���������޸�
    auto l2 = [a, b]() mutable {
        //���޸�
        a++;
    };
    
    //���õ�Ȼ���޸�
    auto l3 = [&a, b]() {
        a++;
        //bΪֵ���ݲ����޸�
        //b++;
    };
    
    //�����������ͣ�
    //�ɱ���д�������
    auto l4 = []() -> string {
        return "";
    };
    
}

void lambda_main()
{
    lambda_test02();
}
