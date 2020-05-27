/*
1437. �Ƿ����� 1 ��������� k ��Ԫ��
����һ�������� 0 �� 1 ��ɵ����� nums �Լ����� k��
������� 1 ��������� k ��Ԫ�أ��򷵻� True �����򣬷��� False ��


ʾ�� 1��
���룺nums = [1,0,0,0,1,0,0,1], k = 2
�����true
���ͣ�ÿ�� 1 ��������� 2 ��Ԫ�ء�
ʾ�� 2��
���룺nums = [1,0,0,1,0,1], k = 2
�����false
���ͣ��ڶ��� 1 �͵����� 1 ֮��ֻ���� 1 ��Ԫ�ء�
ʾ�� 3��
���룺nums = [1,1,1,1,1], k = 0
�����true
ʾ�� 4��
���룺nums = [0,1,0,1], k = 1
�����true
 

��ʾ��

1 <= nums.length <= 10^5
0 <= k <= nums.length
nums[i] ��ֵΪ 0 �� 1
��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
*/
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pre = -1, cur = -1;
	    int ret = -100000;
	    for (int i = 0; i < nums.size(); ++i)
	    {
		    if (nums[i] == 1 && pre < 0 && cur < 0)
			    pre = i;
		    else if (nums[i] == 1 && pre != i)
		    {
			    cur = i;
			    ret = cur - pre - 1;
		    }
		    if (ret == -100000)
			    continue;
		    else if (ret >= k)
			    pre = cur;
		    else if (ret < k)
			    return false;
	    }
	    return true;
    }
};
//���ۣ�
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
	    int pre = -100000;
	    for (int i = 0; i < nums.size(); ++i)
	    {
		    if(nums[i] == 1)
            {
                if(i - pre - 1 < k)
                    return false;
                pre = i;
            }
	    }
	    return true;
    }
};