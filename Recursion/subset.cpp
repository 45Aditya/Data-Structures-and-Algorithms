#include<bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& temp) {
        if(idx==nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums, ans, idx + 1, temp);
        temp.pop_back();
        solve(nums, ans, idx + 1, temp);
    }   
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        solve(nums, ans, 0, temp);
        return ans;
    }
};