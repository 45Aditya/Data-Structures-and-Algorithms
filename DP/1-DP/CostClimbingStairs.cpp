#include<bits/stdc++.h>
using namespace std;

// Recursive + Memoization
class Solution {
    int solve(vector<int>& cost, int i, int n, vector<int>& t) {
        if(i >= n) {
            return 0;
        }
        if(t[i]!=-1) {
            return t[i];
        }
        int next = solve(cost, i+1, n, t);
        int skip = solve(cost, i+2, n, t);
        return t[i] = cost[i] + min(next, skip);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> t(n,-1);
        return min(solve(cost, 0, n, t), solve(cost, 1, n, t));
    }
};

// Bottom Up
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> t(n,-1);
        t[0] = cost[0];
        t[1] = cost[1];
        for(int i=2; i<n; i++) {
            t[i] = cost[i] + min(t[i-1], t[i-2]);
        }
        return min(t[n-1], t[n-2]);
    }
};

//Space Optimization
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1 = cost[0];
        int prev2 = cost[1];
        for(int i=2; i<n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return min(prev1, prev2);
    }
};