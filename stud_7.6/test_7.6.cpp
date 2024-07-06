#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

#include<time.h>
void string_test1() {
    std::string s1("hello world");
    // ʹ�� at �����ʵ������ַ������� "xxx" ׷�ӵ�������
    /*s1.at(2) += "x";*/
    s1.insert(2, "xxx");
    std::cout << s1 << std::endl;
}

void vector_test1()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    vector<int> v2(v1);

    for (size_t i = 0; i < v2.size(); ++i)
    {
        cout << v2[i];

    }
    cout << endl;

    for (size_t i = 0; i < v1.size(); ++i)
    {
        v1[i] *= 2;
        cout << v1[i];

    }
    cout << endl;


}

void vector_test2()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

   /* auto it = v1.begin();*/
    vector<int>::iterator it = v1.begin();
    /*for (; it != v1.end(); ++it)
    {
        cout << *it;
    }
    cout << endl;*/

    while (it != v1.end())
    {
        *it *= 2;
        cout << *it<<" ";
        ++it;
    }
    cout << endl;

    for (auto e : v1)
    {
        e *= 100;
        cout << e << endl;
    }

}

void vector_test3()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    vector<int>::iterator it = v1.begin();

    while (it != v1.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    vector<int>::reverse_iterator rit = v1.rbegin();

    while (rit != v1.rend())
    {
        *rit *= 5;
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
}

void vector_test4()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    cout << v1.size() << endl;
    cout << v1.capacity() << endl;


}

void TestVectorExpand()
{
    size_t sz;
    vector<int> v;
    const size_t n = 10000000;

    size_t begin = clock();
    v.reserve(n);
    sz = v.capacity();
    cout << "making v grow:\n";
    for (int i = 0; i < n; ++i)
    {
        v.push_back(i);
        if (sz != v.capacity())
        {
            sz = v.capacity();
            cout << "capacity changed: " << sz << '\n';
        }
    }
    size_t end = clock();
    cout << "����ʱ��:" << end - begin << endl;
}

//leetcode��ֻ����һ��������Ŀ�Ľⷨ
class Solution1
{
public:
    int singleNumber(vector<int>& nums) { // ����һ������ singleNumber��������һ������ vector ��������Ϊ������������һ������
        int val = 0; // ��ʼ��һ������ val Ϊ 0
        for (auto e : nums) { // ���� nums �е�ÿ��Ԫ�� e
            val ^= e; // ʹ���������� ^= ���� val����ͬ��Ԫ�ػ��໥����������ֻʣ��ֻ����һ�ε�Ԫ��
        }
        return val; // ����ֻ����һ�ε�Ԫ��
    }
};

void vector_test5()
{
    vector<int> v1;
    v1.push_back(20);
    v1.push_back(23);
    v1.push_back(803);
    v1.push_back(25);
    v1.push_back(89);
    v1.push_back(7);
    v1.push_back(17);
    v1.push_back(27);

    for (auto e : v1)
    {
        cout << e << " ";
    }
    cout << endl;

    sort(v1.begin(), v1.end());

    for (auto e : v1)
    {
        cout << e << " ";
    }
    cout << endl;

    v1.erase(v1.begin() + 1);

    for (auto e : v1)
    {
        cout << e << " ";
    }
    cout << endl;

    auto pos = find(v1.begin(), v1.end(), 89);

        if (pos != v1.end())
        {
            v1.erase(pos);
        }
        for (auto e : v1)
        {
            cout << e << " ";
        }
        cout << endl;

        auto pos1 = find(v1.begin(), v1.end(), 100000);

        if (pos1 != v1.end())
        {
            v1.erase(pos1);
        }
        for (auto e : v1)
        {
            cout << e << " ";
        }
        cout << endl;
    
}

//leetcode��ֻ����һ��������Ŀ2�Ľⷨ
class Solution2{
public:
    int singleNumber(vector<int>& nums) { // ����һ������ singleNumber��������һ������ vector ��������Ϊ������������һ������
        int ans = 0; // ��ʼ����Ϊ 0
        for (int i = 0; i < 32; ++i) { // ����ÿһλ�������� 32 λ������
            int count = 0; // ��ʼ����λ�� 1 �ļ���Ϊ 0
            for (auto& num : nums) { // ���������е�ÿ������
                count += (num >> i) & 1; // ͳ�Ƶ�ǰλ�� 1 ������
            }
            if (count % 3) { // ��� 1 ���������� 3 �ı���
                ans |= (1 << i); // ����λ�����ڴ���
            }
        }
        return ans; // ����ֻ����һ�ε�Ԫ��
    }
};

int main() 
{
    string_test1();
    
    vector_test1();
    vector_test2();
    vector_test3();
    vector_test4();
    vector_test5();
    TestVectorExpand(); 

    return 0;
}
