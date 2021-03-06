/*
672. 灯泡开关 Ⅱ
现有一个房间，墙上挂有 n 只已经打开的灯泡和 4 个按钮。在进行了 m 次未知操作后，
你需要返回这 n 只灯泡可能有多少种不同的状态。
假设这 n 只灯泡被编号为 [1, 2, 3 ..., n]，这 4 个按钮的功能如下：

将所有灯泡的状态反转（即开变为关，关变为开）
将编号为偶数的灯泡的状态反转
将编号为奇数的灯泡的状态反转
将编号为 3k+1 的灯泡的状态反转（k = 0, 1, 2, ...)
示例 1:

输入: n = 1, m = 1.
输出: 2
说明: 状态为: [开], [关]
示例 2:

输入: n = 2, m = 1.
输出: 3
说明: 状态为: [开, 关], [关, 开], [关, 关]
示例 3:

输入: n = 3, m = 1.
输出: 4
说明: 状态为: [关, 开, 关], [开, 关, 开], [关, 关, 关], [关, 开, 开].
注意： n 和 m 都属于 [0, 1000].

来源：LeetCode
链接：https://leetcode-cn.com/problems/bulb-switcher-ii/
*/
class Solution {
public:
    int flipLights(int n, int m) {
        if(n == 0 || m == 0)
            return 1;
        
        if(m == 1)
        {
            if(n == 1)
                return 2;
            if(n == 2)
                return 3;
            return 4;
        }
        else if(m == 2)
        {
            if(n == 1)
                return 2;
            if(n == 2)
                return 4;
            return 7;
        }
        else
        {
            if(n == 1)
                return 2;
            if(n == 2)
                return 4;
            return 8;
        }
    }
};


/**
 *  对 n 只灯泡的 m 次未知操作都能用如下的一次操作来表示：
 *  (前面数字表示操作号，方便后面的分析使用)
 *  0.无操作
 *  1.将所有灯泡的状态反转（即开变为关，关变为开）
 *  2.将编号为偶数的灯泡的状态反转
 *  3.将编号为奇数的灯泡的状态反转
 *  4.将编号为 3k+1 的灯泡的状态反转（k = 0, 1, 2, ...)
 *  5.将编号为 3k+2,3k+3 的灯泡的状态反转（k = 0, 1, 2, ...)
 *  6.将编号为 6k+1,6k+2,6k+6 的灯泡的状态反转（k = 0, 1, 2, ...)
 *  7.将编号为 6k+3,6k+5 的灯泡的状态反转（k = 0, 1, 2, ...)
 *
 *  组合操作转换公式如下(1+2=3表示对灯泡进行1,2号两次无序操作，结果等效于只进行一次3号操作)：
 *  //一次操作
 *  0+1=1
 *  0+2=2
 *  0+3=3
 *  0+4=4
 *  //两次操作
 *  1+1=0
 *  2+2=0
 *  3+3=0
 *  4+4=0
 *  1+2=3
 *  1+3=2
 *  1+4=5
 *  2+3=1
 *  2+4=6
 *  3+4=7
 *  1+5=1+(1+4)=(1+1)+4=0+4=4
 *  1+6=1+(2+4)=(1+2)+4=3+4=7
 *  1+7=1+(3+4)=(1+3)+4=2+4=6
 *  2+5=2+(1+4)=(1+2)+4=3+4=7
 *  2+6=2+(2+4)=(2+2)+4=0+4=4
 *  2+7=2+(3+4)=(2+3)+4=1+4=5
 *  3+5=3+(1+4)=(1+3)+4=2+4=6
 *  3+6=3+(2+4)=(2+3)+4=1+4=5
 *  3+7=3+(3+4)=(3+3)+4=0+4=4
 *  4+5=4+(1+4)=(4+4)+1=0+1=1
 *  4+6=4+(2+4)=(4+4)+2=0+2=2
 *  4+7=4+(3+4)=(4+4)+3=0+3=3
 *
 *  第 m 次未知操作(1,2,3,4号操作)后的结果(利用上面的转换公式)：
 *  0.    0  初始状态
 *  1.  ->1234（1,2,3,4 共4种操作）
 *  2.  ->0325,3016,2107,5670 去重（0,1,2,3,5,6,7 共7种操作）
 *  3.  ->1234,0325,3016,2107,4761,7452,6543 去重（0,1,2,3,4,5,6,7 共8种操作）
 *  4+. ->1234,0325,3016,2107,5670,4761,7452,6543 去重（0,1,2,3,4,5,6,7 共8种操作）
 
 *  由上可知：
 *  当 m=0 时，即对初始状态进行0号操作，只有1种状态，即初始全开状态.
 *  当 m=1 时，即对初始状态分别进行1,2,3,4号操作,由灯泡状态表(最下方)可知
 *      当 n=1 时，(1,3,4)号操作后灯泡状态相同，所以有2种不同状态
 *      当 n=2 时，(3,4)号操作后灯泡状态相同，所以有3种不同状态
 *      当 n>2 时，有4种不同状态
 *  当 m=2 时，即对初始状态分别进行0,1,2,3,5,6,7号操作，由灯泡状态表可知
 *      当 n=1 时，(0,2,5,7),(1,3,6)号操作后灯泡状态相同，所以有2种不同状态
 *      当 n=2 时，(0,7),(1,6),(2,5)号操作后灯泡状态相同，所以有4种不同状态
 *      当 n>2 时，有7种不同状态
 *  当 m>2 时，即对初始状态分别进行0,1,2,3,4,5,6,7号操作，由灯泡状态表可知
 *      当 n=1 时，(0,2,5,7),(1,3,4,6)号操作灯泡状态相同，所以有2种不同状态
 *      当 n=2 时，(0,7),(1,6),(2,5),(3,4)号操作灯泡状态相同，所以有4种不同状态
 *      当 n>2 时，有8种不同状态
 *  当 n=0 时，只有1种状态，即无灯状态.
 *
 */