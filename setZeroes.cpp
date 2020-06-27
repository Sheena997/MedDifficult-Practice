/*
73. ��������
����һ�� m x n �ľ������һ��Ԫ��Ϊ 0�����������к��е�����Ԫ�ض���Ϊ 0����ʹ��ԭ���㷨��

ʾ�� 1:

����: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
���: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
ʾ�� 2:

����: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
���: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
����:

һ��ֱ�ӵĽ��������ʹ��  O(mn) �Ķ���ռ䣬���Ⲣ����һ���õĽ��������
һ���򵥵ĸĽ�������ʹ�� O(m + n) �Ķ���ռ䣬������Ȼ������õĽ��������
�������һ�������ռ�Ľ��������

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/set-matrix-zeroes/
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if(m == 0)
            return;
        bool rowRet = false, colRet = false;
        
        //��һ����Ϊ0���򽫸����������׸�Ԫ�أ��������е��׸�Ԫ����Ϊ0
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    if(i == 0)
                        rowRet = true;
                    if(j == 0)
                        colRet = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
            
        }
        
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
        }
        
        
        if(colRet)
        {
            for(int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }
        if(rowRet)
        {
            for(int j = 0; j < n; ++j)
                matrix[0][j] = 0;
        }
    }
};