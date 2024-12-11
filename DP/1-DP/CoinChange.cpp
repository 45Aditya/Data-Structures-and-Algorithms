#include<bits/stdc++.h>
using namespace std;

//top down
class Solution {
    int solve(vector<int>& coins, int amount, int idx, vector<vector<int>>& t) {
        if(idx==0) {
            if(amount%coins[0]==0) {
                return amount / coins[0];
            } 
            return 1e9;
        }
        if(t[idx][amount]!=-1) {
            return t[idx][amount];
        }
        int take = 1e9;
        if(coins[idx] <= amount) {
            take = 1 + solve(coins, amount - coins[idx], idx, t);
        } 
        int skip = solve(coins, amount, idx-1, t);
        return t[idx][amount] = min(take, skip);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> t(n, vector<int>(amount+1, -1));
        int count = solve(coins, amount, n-1, t);
        return (count!=1e9) ? count : -1;
    }
};


//Bottom up
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> t(n, vector<int>(amount+1, -1));
        for(int i=0; i<=amount; i++) {
            if(i%coins[0]==0) {
                t[0][i] = i/coins[0];
            } else {
                t[0][i] = 1e9;
            }
        }
        for(int i=0; i<n; i++) {
            t[i][0] = 0;
        }
        for(int i=1; i<n; i++) {
            for(int j=1; j<=amount; j++) {
                int take = 1e9;
                if(j>=coins[i]) {
                    take = 1 + t[i][j-coins[i]];
                }
                int skip = t[i-1][j];
                t[i][j] = min(take, skip);
            } 
        }
        if(t[n-1][amount]!=1e9) return t[n-1][amount];
        return -1;
    }
};