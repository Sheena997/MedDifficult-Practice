/*
1329. �����󰴶Խ�������
����һ�� m * n ���������� mat �����㽫ͬһ���Խ����ϵ�Ԫ��
�������ϵ����£�����������󣬷����ź���ľ���
ʾ�� 1��
���룺mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
�����[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 

��ʾ��
m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/sort-the-matrix-diagonally/
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