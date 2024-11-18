#include<bits/stdc++.h>
using namespace std;

// Recursive + Memoization
class Solution {
    int solve(int n, vector<int>& t) {
        if(n==1 || n==0) return 1;
        if(t[n]!=-1) return t[n];
        return t[n] = solve(n-1, t) + solve(n-2, t);
    }
public:
    int climbStairs(int n) {
        if(n==1) return n;
        vector<int> t(n+1,-1);
        return solve(n, t);
    }
};

//Bottom Up
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return n;
        vector<int> t(n+1, 0);
        t[0] = t[1] = 1;
        for(int i=2; i<=n; i++) {
            t[i] = t[i-1] + t[i-2];
        }
        return t[n];
    }
};

//Space Optimisation
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return n;
        int prev1 = 1;
        int prev2 = 1; 
        for(int i=2; i<=n; i++) {
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};