/*
1493. ɾ��һ��Ԫ���Ժ�ȫΪ 1 ���������
����һ������������ nums ������Ҫ����ɾ��һ��Ԫ�ء�

������ɾ��Ԫ�صĽ�������У����������ֻ���� 1 �ķǿ�������ĳ��ȡ�

��������������������飬�뷵�� 0 ��

 

��ʾ 1��

���룺nums = [1,1,0,1]
�����3
���ͣ�ɾ��λ�� 2 ������[1,1,1] ���� 3 �� 1 ��
ʾ�� 2��

���룺nums = [0,1,1,1,0,1,1,0,1]
�����5
���ͣ�ɾ��λ�� 4 �����ֺ�[0,1,1,1,1,1,0,1] ���ȫ 1 ������Ϊ [1,1,1,1,1] ��
ʾ�� 3��

���룺nums = [1,1,1]
�����2
���ͣ������Ҫɾ��һ��Ԫ�ء�
ʾ�� 4��

���룺nums = [1,1,0,0,1,1,1,0,1]
�����4
ʾ�� 5��

���룺nums = [0,0,0]
�����0

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/longest-subarray-of-1s-after-deleting-one-element/
*/
//����һ����������
class Solution {
public:
    /*
    ��������
    1.û����0����ָ�������ߣ���¼��
    2.��һ������0�����ܣ���ָ�����������
    3.�ڶ�������0������ָ���Ƶ���һ�� 0 ����һ��λ�ã���Ҫɾ����һ�� 0 ǰ���е� 1
    4.�����δ����0���𰸼�һ
    */
    int longestSubarray(vector<int>& nums) {
        int left = 0, ret = 0, res = 0, sum = 0;
        for(int right = 0; right < nums.size(); ++right)
        {
            if(nums[right] == 1)
            {
                ++sum;
                res = max(sum, res);
            }
            else
            {
                if(ret == 0)
                {
                    ++ret;
                }
                else
                {
                    while(nums[left++] != 0)
                        --sum;
                }
            }
        }
        if(ret == 0)
            --res;
        
        return res;
    }
};

/*
��������
1.sum1 ����м���һ�� 0 �ĺ�
2.sum2 ����м�û�� 0 �ĺ�
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, sum1 = 0, sum2 = 0, res = 0;
        for(int right = 0; right < nums.size(); ++right)
        {
            if(nums[right] == 1)
            {
                ++sum1;
                ++sum2;
                res = max(res, sum1);
            }
            else
            {
                sum1 = sum2;
                sum2 = 0;
            }
        }
        
        return res == nums.size() ? res - 1 : res;
    }
};

 


  


