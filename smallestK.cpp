/*
面试题 17.14. 最小K个数
设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
示例：

输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]
提示：

0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))\

来源：LeetCode
链接：https://leetcode-cn.com/problems/smallest-k-lcci/comments/
*/
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        vector<int> res;
        while(k--)
        {
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};

class Solution {
public:
    void Swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int GetMidIndex(vector<int>& arr, int left, int right)
    {
        int mid = left + (right - left) / 2;
        if(arr[left] < arr[mid])
        {
            if(arr[mid] < arr[right])
                return mid;
            else if(arr[left] < arr[right])
                return right;
            else
                return left;
        }
        else
        {
            if(arr[mid] > arr[right])
                return mid;
            else if(arr[right] > arr[left])
                return left;
            else
                return right;
        }
    }
    int PartSort(vector<int>& arr, int left, int right)
    {
        int mid = GetMidIndex(arr, left, right);
        Swap(arr[mid], arr[right]);
        int key = arr[right];
        while(left < right)
        {
            while(left < right && arr[left] <= key)
                ++left;
            arr[right] = arr[left];
            while(left < right && arr[right] >= key)
                --right;
            arr[left] = arr[right];
        }
        arr[left] = key;
        return left;
   }
    void QuickSort(vector<int>& arr, int left, int right)
    {
        if(left >= right)
            return;
        
        int index = PartSort(arr, left, right);
        QuickSort(arr, left, index - 1);
        QuickSort(arr, index + 1, right);
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        QuickSort(arr, 0, arr.size() - 1);
        
        vector<int> res(arr.begin(), arr.begin() + k);
        
        return res;
    }
};