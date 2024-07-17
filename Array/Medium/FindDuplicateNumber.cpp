#include<bits/stdc++.h>
using namespace std;

// Brute Force
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i]==nums[j]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};

//Better
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> used(n,0);
        for(int i=0; i<n; i++) {
            if(used[nums[i]]==0) {
                used[nums[i]] = 1;
            } else {
                return nums[i];
            }
        }
        return -1;
    }
}; 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i : nums) {
            mp[i]++;
        }
        for(auto it : mp) {
            if(it.second>=2) {
                return it.first;
            }
        }
        return -1;
    }
};

//optimal [Using slow and fast pointer]
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow!=fast);
        slow = 0;
        while(slow!=fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};