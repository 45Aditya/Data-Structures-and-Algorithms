#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& nums, int div, int k) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]%div!=0) {
                sum += nums[i]/div + 1;
            } else {
                sum += nums[i]/div;
            }
        }
        return sum <= k;
    }
public:
    int smallestDivisor(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(check(nums, mid, k)) {
                ans = mid;
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};