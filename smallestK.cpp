class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> res;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < k; ++i)
        {
            res.push_back(arr[i]);
        }
            
        return res;
    }
};