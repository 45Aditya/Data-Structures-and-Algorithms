#include<bits/stdc++.h>
using namespace std;

//Top Down
class Solution {
    int solve(vector<int>& prices, int idx, int flag, int n, vector<vector<int>>& t) {
        if(idx>=n) {
            return 0;
        }
        if(t[idx][flag]!=-1) {
            return t[idx][flag];
        }
        int profit = 0;
        if(flag) {
            profit = max(-prices[idx]+solve(prices, idx+1, 0, n, t), solve(prices, idx+1, flag, n, t));
        } else {
            profit = max(prices[idx]+solve(prices, idx+1, 1, n, t), solve(prices, idx+1, flag, n, t));
        }
        return t[idx][flag] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> t(n, vector<int>(2,-1));
        return solve(prices, 0, 1, n, t);
    }
};

//Bottom Up
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> t(n+1, vector<int>(2,-1));
        t[n][0] = t[n][1] = 0;
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=1; j++) {
                if(j==0) {
                    t[i][j] = max(prices[i]+t[i+1][j+1], t[i+1][j]);
                } else {
                    t[i][j] = max(-prices[i]+t[i+1][j-1], t[i+1][j]);
                }
            }
        }
        return t[0][1];
    }
};


//Space optimised
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2,0), curr(2,0);
        for(int i=n-1; i>=0; i--) {
            curr[0] = max(prices[i]+next[1], next[0]);
            curr[1] = max(-prices[i]+next[0], next[1]);
            next = curr;
        }
        return curr[1];
    }
};