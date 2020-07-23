#include <iostream>
#include "tools.h"

using namespace std;

class Predicate
{
  public:
    //һԪν��
    bool operator()(int i)
    {
        return i > 50;
    }
};

class Pre2
{
  public:
    //��Ԫν��
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
    print_a(v);

    sort(v.begin(), v.end());
    print_a(v);

    sort(v.begin(), v.end(), Pre2());
    print_a(v);
    cout << "-----------------------------------------------";

    //����һԪ�º�����ȡ��
    negate<int> n;
    cout << n(50) << endl;
    //���ö�Ԫ�º������ӷ�
    cout << plus<int>()(10, 20) << endl;
    //���ں�С��
    out_sth_endl(greater<int>()(20, 10), less<int>()(20, 10));

    //ȡ��
    vector<bool> v1;
    for (int i = 0; i < 4; i++)
        v1.push_back(i % 2 == 0);
    print_a(v1);

    vector<bool> v2;
    //����Ĭ��Ԫ��
    v2.resize(v1.size());
    //ת��(���ƻ�ԭ������ȡ��
    //���һ�����������Լ�д�º���
    //����ֵ��T���ɶ�����ÿһ��
    //Ҫ�����˵������в�����
    //��Ӽ��˳�
    transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
    print_a(v2);
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
    print_a(v);

    it = adjacent_find(v.begin(), v.end());
    if (it != v.end())
        cout << *it << endl;

    //���ַ�ֻ�����������У�
    bool bb = binary_search(v.begin(), v.end(), 5);
    if (bb)
        cout << "�ҵ��ˣ�" << endl;

    //����ν��Ҳ����
    int c = count_if(v.begin(), v.end(), greaterThan5);
    cout << "��" << c << "�����ݴ���5��" << endl;
    cout << "-----------------------------------------------";
    
    //�ϲ�
    vector<int> vv, vv2, result;
    for(int i = 10; i <= 70; i += 10)
    {
        vv.push_back(i % 7);
        vv2.push_back(i % 7 + 1);
    }
    
    print_a(vv); print_a(vv2);
    
    result.resize(vv.size() + vv2.size());
    merge(vv.begin(), vv.end(), vv2.begin(), vv2.end(), result.begin());
    print_a(result);
    cout << "-----------------------------------------------";
    
    //��ת
    vector<int> v0 = {10, 20, 30, 40, 50};
    print_a(v0);
    reverse(v0.begin(), v0.end());
    print_a(v0);
    cout << "-----------------------------------------------";
    
    //����
    vector<int> v00 = {10, 20, 30, 40, 50};
    v00.resize(v0.size());
    copy(v0.begin(), v0.end(), v00.begin());
    print_a(v00);
    cout << "-----------------------------------------------";
    
    //�滻ȫ��
    v0.push_back(40);
    replace(v0.begin(), v0.end(), 40, 8848);
    print_a(v0);
    
    replace_if(v0.begin(), v0.end(), is8848, 666);
    print_a(v0);
    cout << "-----------------------------------------------";
    
    //ͬ�����������Ļ���
    print_a(v0); print_a(v);
    swap(v0, v);
    print_a(v0); print_a(v);
    cout << "-----------------------------------------------";
    
    //���
    vector<int> vc;
    for (int i = 0; i < 101; ++i) {
        vc.push_back(i);
    }
    //��ʼ�ۼ�ֵΪ0
    int res = accumulate(vc.begin(), vc.end(), 0);
    cout << res << endl;
    cout << "-----------------------------------------------";
    
    //���
    vector<int> hg = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    fill(hg.begin(), hg.begin() + 3, 100);
    print_a(hg);
    cout << "-----------------------------------------------";
    
    //���ϲ���
    vector<int> a, b, result2;
    for (int i = 0; i < 5; i++)
    {
        a.push_back(i + 1);
        b.push_back(i + 3);
    }
    print_a(a);
    print_a(b);
    
    //����
    result2.resize(min(a.size(), b.size()));
    auto end_it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), result2.begin());
    result2.resize(end_it - result2.begin());
    print_a(result2);
   
    //����
    result2.resize(a.size() + b.size()); 
    end_it = set_union(a.begin(), a.end(), b.begin(), b.end(), result2.begin());
    result2.resize(end_it - result2.begin());
    print_a(result2);
    
    //�
    result2.resize(max(a.size(), b.size()));
    end_it = set_difference(a.begin(), a.end(), b.begin(), b.end(), result2.begin());
    result2.resize(end_it - result2.begin());
    cout << "a - b" << endl;
    print_a(result2);
    
    result2.resize(max(a.size(), b.size()));
    end_it = set_difference(b.begin(), b.end(), a.begin(), a.end(), result2.begin());
    result2.resize(end_it - result2.begin());
    cout << "b - a" << endl;
    print_a(result2);
}
