/*
���ӣ�https://www.nowcoder.com/questionTerminal/fbc417f314f745b1978fc751a54ac8cb?pos=118&orderByHotValue=1
��Դ��ţ����
[�����]24����Ϸ�㷨
�ȶ�ָ����12216ʱ�����ƣ�C/C++ 1�룬��������2��ռ����ƣ�C/C++ 32M����������64M
�㷨֪ʶ��Ƶ����
��������������4��1-10�����֣�ͨ���Ӽ��˳����õ�����Ϊ24����ʤ��
���룺
4��1-10�����֡�[���������ظ�����ÿ�����ֽ�����ʹ��һ�Σ�����������֤���쳣����]
�����
true or false
��������:
����4��int����
�������:
�����ܷ�õ�24�㣬�����true���������false
ʾ��1
����
7 2 1 10
���
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