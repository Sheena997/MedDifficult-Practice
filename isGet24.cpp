/*
链接：https://www.nowcoder.com/questionTerminal/fbc417f314f745b1978fc751a54ac8cb?pos=118&orderByHotValue=1
来源：牛客网
[编程题]24点游戏算法
热度指数：12216时间限制：C/C++ 1秒，其他语言2秒空间限制：C/C++ 32M，其他语言64M
算法知识视频讲解
问题描述：给出4个1-10的数字，通过加减乘除，得到数字为24就算胜利
输入：
4个1-10的数字。[数字允许重复，但每个数字仅允许使用一次，测试用例保证无异常数字]
输出：
true or false
输入描述:
输入4个int整数
输出描述:
返回能否得到24点，能输出true，不能输出false
示例1
输入
7 2 1 10
输出
true
*/
#include <iostream>
#include <vector>

using namespace std;

bool isGet24(vector<int> v, double res)
{
    if(v.empty())
        return res == 24;
    
    for(int i = 0; i < v.size(); ++i)
    {
        vector<int> ret(v);
        ret.erase(ret.begin() + i);
        if(isGet24(ret, res + v[i])
        || isGet24(ret, res - v[i])
        || isGet24(ret, res * v[i])
        || isGet24(ret, res / v[i]))
            return true;
    }
    
    return false;
}
int main()
{
    vector<int> v(4,0);
    
    while(cin >> v[0] >> v[1] >> v[2] >> v[3])
    {
        if(isGet24(v, 0))
            cout << "true" << endl;
        else 
            cout << "false" << endl;
    }
    
    return 0;
}