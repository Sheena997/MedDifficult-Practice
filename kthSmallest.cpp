/*
378. ��������е�KС��Ԫ��
����һ�� n x n ��������ÿ�к�ÿ��Ԫ�ؾ������������ҵ������е� k С��Ԫ�ء�
��ע�⣬���������ĵ� k СԪ�أ������ǵ� k ����ͬ��Ԫ�ء�
 
ʾ����

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
���� 13��
 

��ʾ��
����Լ��� k ��ֵ��Զ����Ч�ģ�1 �� k �� n2 ��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/
*/
class Solution {
public:
    int countTheSmallerNum(vector<vector<int>> matrix, int num)
    {
        int count = 0;
        int left = 0, right = matrix[0].size() - 1;
        while(left < matrix.size() && right >= 0)
        {
            if(matrix[left][right] > num)
            {
                --right;
            }
            else 
            {
                count += (right + 1);
                ++left;
            }
        }
        
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix[matrix.size() - 1][matrix[0].size() - 1];
        int mid = 0;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            
            if(countTheSmallerNum(matrix, mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};