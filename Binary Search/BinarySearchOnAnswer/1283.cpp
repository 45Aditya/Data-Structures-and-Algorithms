#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool valid(vector<int>& nums, int t, int m) {
        int sum = 0;
        for(auto it: nums){
            sum += ceil(float(it)/float(m)) ;
        }
        return sum <= t ;
    }
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(l<=h) {
            int m = (l+h) >> 1;
            if(valid(nums, t, m)==true) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};