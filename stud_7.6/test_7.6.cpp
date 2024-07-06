#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

#include<time.h>
void string_test1() {
    std::string s1("hello world");
    // 使用 at 来访问第三个字符，并将 "xxx" 追加到它后面
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
    cout << "消耗时间:" << end - begin << endl;
}

//leetcode上只出现一次数字题目的解法
class Solution1
{
public:
    int singleNumber(vector<int>& nums) { // 定义一个函数 singleNumber，它接受一个整数 vector 的引用作为参数，并返回一个整数
        int val = 0; // 初始化一个变量 val 为 0
        for (auto e : nums) { // 对于 nums 中的每个元素 e
            val ^= e; // 使用异或操作符 ^= 更新 val，相同的元素会相互抵消，最终只剩下只出现一次的元素
        }
        return val; // 返回只出现一次的元素
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

//leetcode上只出现一次数字题目2的解法
class Solution2{
public:
    int singleNumber(vector<int>& nums) { // 定义一个函数 singleNumber，它接受一个整数 vector 的引用作为参数，并返回一个整数
        int ans = 0; // 初始化答案为 0
        for (int i = 0; i < 32; ++i) { // 对于每一位（假设是 32 位整数）
            int count = 0; // 初始化该位上 1 的计数为 0
            for (auto& num : nums) { // 遍历数组中的每个数字
                count += (num >> i) & 1; // 统计当前位上 1 的数量
            }
            if (count % 3) { // 如果 1 的数量不是 3 的倍数
                ans |= (1 << i); // 将该位设置在答案中
            }
        }
        return ans; // 返回只出现一次的元素
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
