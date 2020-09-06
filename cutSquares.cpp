/*
面试题 16.13. 平分正方形
给定两个正方形及一个二维平面。请找出将这两个正方形分割成两半的一条直线。假设正方形顶边和底边与 x 轴平行。

每个正方形的数据square包含3个数值，正方形的左下顶点坐标[X,Y] = [square[0],square[1]]，以及正方形的边长square[2]。所求直线穿过两个正方形会形成4个交点，请返回4个交点形成线段的两端点坐标（两个端点即为4个交点中距离最远的2个点，这2个点所连成的线段一定会穿过另外2个交点）。2个端点坐标[X1,Y1]和[X2,Y2]的返回格式为{X1,Y1,X2,Y2}，要求若X1 != X2，需保证X1 < X2，否则需保证Y1 <= Y2。

若同时有多条直线满足要求，则选择斜率最大的一条计算并返回（与Y轴平行的直线视为斜率无穷大）。

示例：

输入：
square1 = {-1, -1, 2}
square2 = {0, -1, 2}
输出： {-1,0,2,0}
解释： 直线 y = 0 能将两个正方形同时分为等面积的两部分，返回的两线段端点为[-1,0]和[2,0]
提示：

square.length == 3
square[2] > 0

来源：LeetCode
链接：https://leetcode-cn.com/problems/bisect-squares-lcci/
*/

class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        //square1存放横坐标较小的点
        if(square1[0] >=square2[0] || (square1[0] == square2[0] && square1[1] > square2[1]))
            swap(square1, square2);
        
        //求两个正方形各自的中心点
        double rx1 = square1[0] + square1[2] / 2.0;
        double ry1 = square1[1] + square1[2] / 2.0;
        double rx2 = square2[0] + square2[2] / 2.0;
        double ry2 = square2[1] + square2[2] / 2.0;
        
        //斜率不存在，则表示与y轴平行
        if(rx1 == rx2)
        {
            //下边确定，主要找上边
            return {rx1, ry1 - square1[2] / 2.0, rx1, max(ry1 + square1[2] / 2.0, ry2 + square2[2] / 2.0)};
        }
        else
        {
            double k = (ry2 - ry1) / (rx2 - rx1);
            double b = ry1 - k * rx1;
            
            if(abs(k) <= 1)
            {
                //斜率绝对值小于1，与左右两边交
                double l = square1[0], r = max(rx1 + square1[2] / 2.0, rx2 + square2[2] / 2.0);
                return {l, k * l + b, r, k * r + b};
            }
            else
            {
                //斜率绝对值大于1，与上下两边交
                double d = min(square1[1], square2[1]);
                double u = max(ry1 + square1[2] / 2.0, ry2 + square2[2] / 2.0);
                double xd = (d - b) / k, xu = (u - b) / k;
                if(xd < xu || (xd == xu && d < u))
                    return {xd, d, xu, u};
                return {xu, u, xd, d};
            }
        }
        
    }
};