#include <iostream>
#include "tools.h"

using namespace std;

int get3();
int get5();
void show(int (*)());

void ptr3_main()
{
    //��ͨд��
    int (*get)();

    //��typedef
    /*
    typedef int (*getTemplate)(); 
    getTemplate get;
    */

    //��c++auto(�൱��java10��var)
    //auto get0 = get3;
    cout << "get what?" << endl;
    
    int i;
/*   ������cin.get()�����ȼ���getchar()
���ڻ�ȡ�����ַ����޲���ʱ��������
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
