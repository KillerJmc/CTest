#include <iostream>
#include <vector>
#include <tools>
#include <algorithm>
#include <numeric>

using namespace std;

class Predicate
{
  public:
    //一元谓词
    bool operator()(int i)
    {
        return i > 50;
    }
};

class Pre2
{
  public:
    //二元谓词
    bool operator()(int i, int k)
    {
        return i > k;
    }
};

bool greaterThan5(int i)
{
    return i > 5;
}

bool is8848(int i)
{
    return i == 8848; 
}

void algorithm_main()
{
    vector<int> v;
    for (int i = 10; i <= 100; i+= 10)
        v.push_back(i);
    auto it = find_if(v.begin(), v.end(), Predicate());
    if (it != v.end())
        cout << *it << endl;
    cout << "-----------------------------------------------";

    v.clear();
    for(int i = 10; i <= 70; i += 10)
        v.push_back(i % 7);
    tools::print_stl(v);

    sort(v.begin(), v.end());
    tools::print_stl(v);

    sort(v.begin(), v.end(), Pre2());
    tools::print_stl(v);
    cout << "-----------------------------------------------";

    //内置一元仿函数：取反
    negate<int> n;
    cout << n(50) << endl;
    //内置二元仿函数：加法
    cout << plus<int>()(10, 20) << endl;
    //大于和小于
    tools::print({greater<int>()(20, 10), less<int>()(20, 10)});

    //取反
    vector<bool> v1;
    for (int i = 0; i < 4; i++)
        v1.push_back(i % 2 == 0);
    tools::print_stl(v1);

    vector<bool> v2;
    //创建默认元素
    v2.resize(v1.size());
    //转移(不破坏原来）并取反
    //最后一个参数可以自己写仿函数
    //返回值是T，可对序列每一个
    //要被搬运的数进行操作，
    //如加减乘除
    transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
    tools::print_stl(v2);
    cout << "-----------------------------------------------";

    v.clear();
    for (int i = 10; i <= 100; i+= 10)
        v.push_back(i);
    it = find(v.begin(), v.end(), 50);
    if (it != v.end())
        cout << *it << endl;
    cout << "-----------------------------------------------";

    v.clear();
    for (int i = 10; i <= 100; i+= 10)
        v.push_back(i % 7);
    sort(v.begin(), v.end());
    tools::print_stl(v);

    it = adjacent_find(v.begin(), v.end());
    if (it != v.end())
        cout << *it << endl;

    //二分法只能找有序序列！
    bool bb = binary_search(v.begin(), v.end(), 5);
    if (bb)
        cout << "找到了！" << endl;

    //或者谓词也可以
    int c = count_if(v.begin(), v.end(), greaterThan5);
    cout << "有" << c << "个数据大于5！" << endl;
    cout << "-----------------------------------------------";
    
    //合并
    vector<int> vv, vv2, result;
    for(int i = 10; i <= 70; i += 10)
    {
        vv.push_back(i % 7);
        vv2.push_back(i % 7 + 1);
    }
    
    tools::print_stl(vv); tools::print_stl(vv2);
    
    result.resize(vv.size() + vv2.size());
    merge(vv.begin(), vv.end(), vv2.begin(), vv2.end(), result.begin());
    tools::print_stl(result);
    cout << "-----------------------------------------------";
    
    //反转
    vector<int> v0 = {10, 20, 30, 40, 50};
    tools::print_stl(v0);
    reverse(v0.begin(), v0.end());
    tools::print_stl(v0);
    cout << "-----------------------------------------------";
    
    //拷贝
    vector<int> v00 = {10, 20, 30, 40, 50};
    v00.resize(v0.size());
    copy(v0.begin(), v0.end(), v00.begin());
    tools::print_stl(v00);
    cout << "-----------------------------------------------";
    
    //替换全部
    v0.push_back(40);
    replace(v0.begin(), v0.end(), 40, 8848);
    tools::print_stl(v0);
    
    replace_if(v0.begin(), v0.end(), is8848, 666);
    tools::print_stl(v0);
    cout << "-----------------------------------------------";
    
    //同种类型容器的互换
    tools::print_stl(v0); tools::print_stl(v);
    swap(v0, v);
    tools::print_stl(v0); tools::print_stl(v);
    cout << "-----------------------------------------------";
    
    //求和
    vector<int> vc;
    for (int i = 0; i < 101; ++i) {
        vc.push_back(i);
    }
    //起始累加值为0
    int res = accumulate(vc.begin(), vc.end(), 0);
    cout << res << endl;
    cout << "-----------------------------------------------";
    
    //填充
    vector<int> hg = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fill(hg.begin(), hg.begin() + 3, 100);
    tools::print_stl(hg);
    cout << "-----------------------------------------------";
    
    //集合操作
    vector<int> a, b, result2;
    for (int i = 0; i < 5; i++)
    {
        a.push_back(i + 1);
        b.push_back(i + 3);
    }
    tools::print_stl(a);
    tools::print_stl(b);
    
    //交集
    result2.resize(min(a.size(), b.size()));
    auto end_it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), result2.begin());
    result2.resize(end_it - result2.begin());
    tools::print_stl(result2);
   
    //并集
    result2.resize(a.size() + b.size()); 
    end_it = set_union(a.begin(), a.end(), b.begin(), b.end(), result2.begin());
    result2.resize(end_it - result2.begin());
    tools::print_stl(result2);
    
    //差集
    result2.resize(max(a.size(), b.size()));
    end_it = set_difference(a.begin(), a.end(), b.begin(), b.end(), result2.begin());
    result2.resize(end_it - result2.begin());
    cout << "a - b" << endl;
    tools::print_stl(result2);
    
    result2.resize(max(a.size(), b.size()));
    end_it = set_difference(b.begin(), b.end(), a.begin(), a.end(), result2.begin());
    result2.resize(end_it - result2.begin());
    cout << "b - a" << endl;
    tools::print_stl(result2);
}
