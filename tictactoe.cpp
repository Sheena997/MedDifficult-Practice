/*
������ 16.04. ������Ϸ
���һ���㷨���ж�����Ƿ�Ӯ�˾�����Ϸ��������һ�� N x N ���������̣�
���ַ�" "��"X"��"O"��ɣ������ַ�" "����һ����λ��

�����Ǿ�����Ϸ�Ĺ���

����������ַ������λ��" "���С�
��һ��������Ƿ��ַ�"O"���ҵڶ���������Ƿ��ַ�"X"��
"X"��"O"ֻ��������ڿ�λ�У���������ѷ����ַ���λ�ý�����䡣
����N����ͬ���ҷǿգ����ַ�����κ��С��л�Խ���ʱ����Ϸ��������Ӧ���ַ�����һ�ʤ��
������λ�÷ǿ�ʱ��Ҳ��Ϊ��Ϸ������
�����Ϸ��������Ҳ������ٷ����ַ���
�����Ϸ���ڻ�ʤ�ߣ��ͷ��ظ���Ϸ�Ļ�ʤ��ʹ�õ��ַ���"X"��"O"���������Ϸ��ƽ�ֽ�����
�򷵻� "Draw"������Ի����ж�����Ϸδ���������򷵻� "Pending"��

ʾ�� 1��

���룺 board = ["O X"," XO","X O"]
����� "X"
ʾ�� 2��

���룺 board = ["OOX","XXO","OXO"]
����� "Draw"
���ͣ� û����һ�ʤ�Ҳ����ڿ�λ
ʾ�� 3��

���룺 board = ["OOX","XXO","OX "]
����� "Pending"
���ͣ� û����һ�ʤ���Դ��ڿ�λ
��ʾ��

1 <= board.length == board[i].length <= 100
����һ����ѭ���������

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/tic-tac-toe-lcci/
*/
class Solution {
public:
    string tictactoe(vector<string>& board) {
        int n = board.size();
        int sum = 0, flag = 1;
        for(int i = 0; i < board.size(); ++i)
        {
            sum = 0;
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == 'X')
                    ++sum;
                if(board[i][j] == 'O')
                    --sum;
                if(board[i][j] == ' ')
                    flag = 0;
            }
            if(sum == n)
                return "X";
            else if(sum == -n)
                return "O";
        }
        for(int j = 0; j < n; ++j)
        {
            sum = 0;
            for(int i = 0; i < n; ++i)
            {
                if(board[i][j] == 'X')
                    ++sum;
                if(board[i][j] == 'O')
                    --sum;
            }
            if(sum == n)
                return "X";
            else if(sum == -n)
                return "O";
        }
        
        sum = 0;
        for(int i = 0; i < board.size(); ++i)
        {
            if(board[i][n - i - 1] == 'X')
                ++sum;
            if(board[i][n - i - 1] == 'O')
                --sum;
        }
        if(sum == n)
            return "X";
        else if(sum == -n)
            return "O";
        
        sum = 0;
        for(int i = 0; i < board.size(); ++i)
        {
            if(board[i][i] == 'X')
                ++sum;
            if(board[i][i] == 'O')
                --sum;
        }
        if(sum == n)
            return "X";
        else if(sum == -n)
            return "O";
        if(flag == 0)
            return "Pending";
        return "Draw";
    }
};