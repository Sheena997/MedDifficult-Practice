/*
973. ��ӽ�ԭ��� K ����
������һ����ƽ���ϵĵ���ɵ��б� points����Ҫ�����ҳ� K ������ԭ�� (0, 0) ����ĵ㡣
�����ƽ��������֮��ľ�����ŷ����¾��롣��
����԰��κ�˳�򷵻ش𰸡����˵������˳��֮�⣬��ȷ����Ψһ�ġ�

ʾ�� 1��

���룺points = [[1,3],[-2,2]], K = 1
�����[[-2,2]]
���ͣ� 
(1, 3) ��ԭ��֮��ľ���Ϊ sqrt(10)��
(-2, 2) ��ԭ��֮��ľ���Ϊ sqrt(8)��
���� sqrt(8) < sqrt(10)��(-2, 2) ��ԭ�������
����ֻ��Ҫ����ԭ������� K = 1 ���㣬���Դ𰸾��� [[-2,2]]��
ʾ�� 2��

���룺points = [[3,3],[5,-1],[-2,4]], K = 2
�����[[3,3],[-2,4]]
���� [[-2,4],[3,3]] Ҳ�ᱻ���ܡ���
 

��ʾ��

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/k-closest-points-to-origin/
*/
//���۵�
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        multimap<int, vector<int>> mp;
        for(int i = 0; i < points.size(); ++i)
        {
            int des = ((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
            vector<int> vc(2, 0);
            vc[0] = points[i][0];
            vc[1] = points[i][1];
            mp.insert(make_pair(des, vc));
            vc.push_back(des);
        }
        
        int i = 0;
        for(auto e : mp)
        {
            if(i >= K)
                break;
            res.push_back(e.second);
            ++i;
        }
        
        return res;
    }
};

//�Լ���
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res(K, vector<int>(2, 0));
        multimap<int, int> mp;
        vector<int> vc;
        for(int i = 0; i < points.size(); ++i)
        {
            int des = ((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
            mp.insert(make_pair(des, i));
            vc.push_back(des);
        }
        sort(vc.begin(), vc.end());
        int i = 0;
        for(auto e : mp)
        {
            if(i >= K)
                break;
            res[i][0] = points[e.second][0];
            res[i][1] = points[e.second][1];
            ++i;
        }
        
        return res;
    }
};