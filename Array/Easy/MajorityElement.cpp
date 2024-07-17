#include<bits/std.c++.h>
using namespace std;

// Brute Force

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i : nums) {
            mp[i]++;
        }
        int maxi = INT_MIN;
        int element = -1;
        for(auto it : mp) {
            if(maxi < it.second) {
                maxi = it.second;
                element = it.first;
            }
        }
        return element;
    }
};

// Optimal (Moore's Voting Algorithm)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(count==0) {
                candidate = nums[i];
                count++;
            } else if(nums[i]==candidate) {
                count++;
            } else {
                count--;
            }
        }
        count = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]==candidate) {
                count++;
            }
        }
        return (count > n/3) ? candidate : -1;
    }
};