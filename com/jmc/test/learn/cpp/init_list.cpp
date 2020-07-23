#include <iostream>
#include "tools.h"

using namespace std;

//�ܶ���ĳ�ʼ�������������ʼ���б���Ϊ���������Խ��ղ�������
//{elements}�ᱻ������ֱ�ӵ���initializer_list
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
            cout << "Ĭ�Ϲ��죺"
                     << a + b << endl;
        }
        
        add(initializer_list<int> l)
        {
            int result = 0;
            for (int i : l) result += i;
            
            cout << "�ɱ�������죺"
                     << result << endl;
        }
};

void init_list_main()
{
    print({1, 2, 3, 4, 5});
    add(3, 4);
    add({3, 4});
    add({1, 2, 3, 4, 5});
    //�ܶຯ��֧�ֿɱ������
    cout << max({1, 2, 3, 4, 5}) << endl;
    cout << "-----------------------------------------------";
    
    //auto&����Ԫ�ض���ó��Ķ�
    //��ָ�룬ֻռ4���ֽڣ�ʡ�ڴ�
    //��ҪС�ģ����������޸�
    //�����ڲ�����(������const��װ)
    for (const auto& i : {1, 3, 5, 7, 9})
        cout << i << '\t';
    cout << endl;
    
    
}
