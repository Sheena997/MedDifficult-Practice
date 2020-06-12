/*
421. ��������������������ֵ
����һ���ǿ����飬������Ԫ��Ϊ a0, a1, a2, �� , an-1������ 0 �� ai < 231 ��

�ҵ� ai ��aj ������� (XOR) ������������0 �� i,  j < n ��

������O(n)��ʱ�������������

ʾ��:

����: [3, 10, 5, 25, 2, 8]

���: 28

����: ���Ľ���� 5 ^ 25 = 28.
ͨ������4,653�ύ����7,974

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/
*/
/*
    ��һ�� 2^n > 2^(n-1) + 2^(n-2) + .. 2^0�����ԣ��Ӹ�λ����λ�ߣ�ÿһλ�������Ϊ1����ôһ�������·��
    �ڶ�����һ�ɵã�����һ��ʼ�Ӹ�λ��ʼ���£�������ʱ�����ǵ�λ��������ο���ȡÿһ�����ֵ�ָ����λ
        mask |= (1 << i);
        nums_mask = mask & nums[j]
        ����������ȡ��ÿһ�����ֵ�ָ��ǰnλ
    ������ a ^ b  = c ��ô a ^ c = b, b ^ c = a
        ���Ǽ�����һλ�Ľ��Ϊ1
        ��ô��� nums_mask_one ^ res = nums_mask_two
        ��ô���res�������ˣ���������
*/
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for(int i = 31; i >= 0; --i)
        {
            mask |= (1 << i);
            unordered_set<int> pre_set;
            for(int j = 0; j < nums.size(); ++j)
                pre_set.insert(mask & nums[j]);
            int tmp = res | (1 << i);
            unordered_set<int>::iterator prit = pre_set.begin();
            while(prit != pre_set.end())
            {
                int val = tmp ^ *prit;
                if(pre_set.count(val) != 0)
                {
                    res = tmp;
                    break;
                }
                ++prit;
            }
        }
        
        return res;
    }
};
          
       