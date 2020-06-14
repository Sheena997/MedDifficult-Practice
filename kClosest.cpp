/*
973. 最接近原点的 K 个点
我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。
（这里，平面上两点之间的距离是欧几里德距离。）
你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

示例 1：

输入：points = [[1,3],[-2,2]], K = 1
输出：[[-2,2]]
解释： 
(1, 3) 和原点之间的距离为 sqrt(10)，
(-2, 2) 和原点之间的距离为 sqrt(8)，
由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
示例 2：

输入：points = [[3,3],[5,-1],[-2,4]], K = 2
输出：[[3,3],[-2,4]]
（答案 [[-2,4],[3,3]] 也会被接受。）
 

提示：

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000

来源：LeetCode
链接：https://leetcode-cn.com/problems/k-closest-points-to-origin/
*/
//评论的
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

//自己的
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