#include<bits/stdc++.h>
using namespace std;

//Brute Force
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2,-1);
        for(int i=0; i<n; i++) {
            if(nums[i]==target && ans[0]==-1) {
                ans[0] = i;
                ans[1] = i;
            } else if(nums[i]==target && nums[i]==nums[i-1]) {
                ans[1] = i;
            }   
        }
        return ans;
    }
};


//Using Binary Search
class Solution {
    void search(vector<int>& nums, vector<int>& ans, int target, int left, int right) {
        if (left > right) return;

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            if (ans[0] == -1 || mid < ans[0]) {
                ans[0] = mid; 
                search(nums, ans, target, left, mid - 1); 
            }
            if (ans[1] == -1 || mid > ans[1]) {
                ans[1] = mid; 
                search(nums, ans, target, mid + 1, right); 
            }
        } else if (nums[mid] > target) {
            search(nums, ans, target, left, mid - 1);
        } else {
            search(nums, ans, target, mid + 1, right);
        }
    } 

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int n = nums.size();
        if (n == 0) return ans;

        search(nums, ans, target, 0, n - 1);

        return ans;
    }
};
