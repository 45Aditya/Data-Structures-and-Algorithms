#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& stalls, int dis, int k) {
        int cnt = 1;
        int last_pos = stalls[0];
        for(int i=1; i<stalls.size(); i++) {
            if(stalls[i] - last_pos >= dis) {
                cnt++;
                last_pos = stalls[i];
            }
        }
        return cnt >= k;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int l = 1;
        int h = stalls[n-1] - stalls[0];
        int ans = -1;
        while(l <= h) {
            int mid = l + (h-l)/2;
            if(check(stalls, mid, k)) {
                ans = mid;
                l = mid+1;
            } else {
                h = mid-1;
            }
        }
        return ans;
    }
};