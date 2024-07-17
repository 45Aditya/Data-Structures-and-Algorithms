#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        long long diff = INT_MAX;
        sort(a.begin(), a.end());
        for (long long i = 0; i <= n - m; i++) {
            long long currentDiff = a[i + m - 1] - a[i];
            diff = min(diff, currentDiff);
        }
        return diff;
    }   
};