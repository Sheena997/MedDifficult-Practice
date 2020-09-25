/*
1329. 将矩阵按对角线排序
给你一个 m * n 的整数矩阵 mat ，请你将同一条对角线上的元素
（从左上到右下）按升序排序后，返回排好序的矩阵。
示例 1：
输入：mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
输出：[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 

提示：
m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100

来源：LeetCode
链接：https://leetcode-cn.com/problems/sort-the-matrix-diagonally/
*/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int end = min(mat.size(), mat[0].size());
        
        while(end--)
        {
            for(int i = 0; i < mat.size() - 1; ++i)
            {
                for(int j = 0; j < mat[i].size() - 1; ++j)
                {
                    if(mat[i][j] > mat[i + 1][j + 1])
                        swap(mat[i][j], mat[i + 1][j + 1]);
                }
            }
        }
        
        return mat;
    }
};