#include <iostream>
#include <vector>
#include <tools>

using namespace std;

template<class T>
using V = vector<T>;

/*a typedef cannot be a template
template<class T>
typedef vector<T> V;
*/

//两者相同
using func = void(*)(int, int);
typedef void(*func2)(int, int);

void alias_main()
{
    //alias：别名可以做到define
    //和typedef所不能做到的
    //事：包含模板
    V<int> v;
    tools::print_stl(v);
}
