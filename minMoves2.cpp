/*
462. �����ƶ�����ʹ����Ԫ����� II
����һ���ǿ��������飬�ҵ�ʹ��������Ԫ�������
�����С�ƶ���������ÿ���ƶ��ɽ�ѡ����һ��Ԫ��
��1���1�� �����Լ�������ĳ������Ϊ10000��

����:

����:
[1,2,3]

���:
2

˵����
ֻ�����������Ǳ�Ҫ�ģ��ǵ�ÿһ������ʹ����һ��Ԫ�ؼ�1���1���� 

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii/
*/
//�����ȵ�����λ��
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i = 0, j = nums.size() - 1;
        int res = 0;
        while(i < j)
        {
            res += (nums[j--] - nums[i++]);
        }
        
        return res;
    }
};