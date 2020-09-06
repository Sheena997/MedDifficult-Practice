/*
������ 16.13. ƽ��������
�������������μ�һ����άƽ�档���ҳ��������������ηָ�������һ��ֱ�ߡ����������ζ��ߺ͵ױ��� x ��ƽ�С�

ÿ�������ε�����square����3����ֵ�������ε����¶�������[X,Y] = [square[0],square[1]]���Լ������εı߳�square[2]������ֱ�ߴ������������λ��γ�4�����㣬�뷵��4�������γ��߶ε����˵����꣨�����˵㼴Ϊ4�������о�����Զ��2���㣬��2���������ɵ��߶�һ���ᴩ������2�����㣩��2���˵�����[X1,Y1]��[X2,Y2]�ķ��ظ�ʽΪ{X1,Y1,X2,Y2}��Ҫ����X1 != X2���豣֤X1 < X2�������豣֤Y1 <= Y2��

��ͬʱ�ж���ֱ������Ҫ����ѡ��б������һ�����㲢���أ���Y��ƽ�е�ֱ����Ϊб������󣩡�

ʾ����

���룺
square1 = {-1, -1, 2}
square2 = {0, -1, 2}
����� {-1,0,2,0}
���ͣ� ֱ�� y = 0 �ܽ�����������ͬʱ��Ϊ������������֣����ص����߶ζ˵�Ϊ[-1,0]��[2,0]
��ʾ��

square.length == 3
square[2] > 0

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/bisect-squares-lcci/
*/

class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        //square1��ź������С�ĵ�
        if(square1[0] >=square2[0] || (square1[0] == square2[0] && square1[1] > square2[1]))
            swap(square1, square2);
        
        //�����������θ��Ե����ĵ�
        double rx1 = square1[0] + square1[2] / 2.0;
        double ry1 = square1[1] + square1[2] / 2.0;
        double rx2 = square2[0] + square2[2] / 2.0;
        double ry2 = square2[1] + square2[2] / 2.0;
        
        //б�ʲ����ڣ����ʾ��y��ƽ��
        if(rx1 == rx2)
        {
            //�±�ȷ������Ҫ���ϱ�
            return {rx1, ry1 - square1[2] / 2.0, rx1, max(ry1 + square1[2] / 2.0, ry2 + square2[2] / 2.0)};
        }
        else
        {
            double k = (ry2 - ry1) / (rx2 - rx1);
            double b = ry1 - k * rx1;
            
            if(abs(k) <= 1)
            {
                //б�ʾ���ֵС��1�����������߽�
                double l = square1[0], r = max(rx1 + square1[2] / 2.0, rx2 + square2[2] / 2.0);
                return {l, k * l + b, r, k * r + b};
            }
            else
            {
                //б�ʾ���ֵ����1�����������߽�
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