#include <iostream>
#include "tools.h"

using namespace std;

template<class T>
using V = vector<T>;

/*a typedef cannot be a template
template<class T>
typedef vector<T> V;
*/

//������ͬ
using func = void(*)(int, int);
typedef void(*func2)(int, int);

void alias_main()
{
    //alias��������������define
    //��typedef������������
    //�£�����ģ��
    V<int> v;
    print_a(v);
}
