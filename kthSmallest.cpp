/*
378. 有序矩阵中第K小的元素
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。
 
示例：

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
返回 13。
 

提示：
你可以假设 k 的值永远是有效的，1 ≤ k ≤ n2 。

来源：LeetCode
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/
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