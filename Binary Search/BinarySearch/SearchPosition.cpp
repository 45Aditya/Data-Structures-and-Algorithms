#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(nums[mid]==target) {
                return mid;
            } else if(nums[mid] < target) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};