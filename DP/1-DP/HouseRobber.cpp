#include<bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
    int solve(vector<int>& nums, int idx, int n, vector<int>& t) {
        if(idx>=n) return 0;
        if(t[idx]!=-1) {
            return t[idx];
        }
        int take = nums[idx] + solve(nums, idx+2, n, t);
        int skip = solve(nums, idx+1, n, t);
        return t[idx] = max(take, skip);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> t(n, -1);
        return solve(nums, 0, n, t);
    }
};


//Bottom - Up
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];        
        vector<int> t(n, -1);
        t[0] = nums[0];
        t[1] = max(nums[0], nums[1]);       
        for (int i = 2; i < n; i++) {
            t[i] = max(nums[i] + t[i-2], t[i-1]);
        }
        return t[n-1];
    }
};