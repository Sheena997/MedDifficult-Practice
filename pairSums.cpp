/*
������ 16.24. ���Ժ�
���һ���㷨���ҳ�����������֮��Ϊָ��ֵ�����������ԡ�һ����ֻ������һ�����ԡ�

ʾ�� 1:

����: nums = [5,6,5], target = 11
���: [[5,6]]
ʾ�� 2:

����: nums = [5,6,5,6], target = 11
���: [[5,6],[5,6]]
��ʾ��

nums.length <= 100000

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/pairs-with-sum-lcci/
*/
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> res;
        unordered_map<int, int> unmp;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(unmp[target - nums[i]] != 0)
            {
                res.push_back({target - nums[i], nums[i]});
                --unmp[nums[i]];
                --unmp[target - nums[i]];
            }
            ++unmp[nums[i]];
        }
        
        return res;
    }
};


   