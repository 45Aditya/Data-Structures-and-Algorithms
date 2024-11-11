// Question Link = https://leetcode.com/problems/minimum-time-to-complete-trips/description/
#include<bits/stdc++.h>
using namespace std;


class Solution {
    bool check(vector<int>& time, int total, long long t) {
        int n = time.size();
        long long cnt = 0;
        for(int i=0; i<n; i++) {
            cnt += (t / time[i]*1ll); 
        }
        return cnt >= total;
    } 
public:
    long long minimumTime(vector<int>& time, int t) {
        int n = time.size();
        sort(time.begin(), time.end());
        long long l = 0;
        long long h = time.back() * static_cast<long long>(t);
        long long ans = h;
        while(l <= h) {
            long long mid = l + (h-l) / 2;
            if(check(time, t, mid)==true) {
                h = mid - 1;
                ans = min(ans,mid);
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};