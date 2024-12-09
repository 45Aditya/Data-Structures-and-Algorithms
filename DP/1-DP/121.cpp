#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        st.push(nums[n-1]);
        ans[n-1] = 0;
        for(int i=n-2; i>=0; i--) {
            int res = st.top() - nums[i];
            if(st.top() < nums[i]) {
                st.push(nums[i]);
            }
            ans[i] = res;
        }
        return *max_element(ans.begin(), ans.end());
    }
};