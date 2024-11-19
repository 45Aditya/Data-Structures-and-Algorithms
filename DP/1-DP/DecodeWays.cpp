#include<bits/stdc++.h>
using namespace std;

// Recursion + Memoization
class Solution {
    int solve(string& s, int idx, int n, vector<int>& t) {
        if (idx == n) return 1; 
        if (s[idx] == '0') return 0; 
        if(t[idx]!=-1) {
            return t[idx];
        }
        int one = solve(s, idx+1, n, t);
        int two = 0;
        if(idx+1 < n && (s[idx]=='1' || (s[idx]=='2' && s[idx+1]<='6'))) {
            two = solve(s, idx+2, n, t);
        } 
        return t[idx] = one + two;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        if (s[0] == '0') return 0;
        vector<int> t(n+1, -1);
        return solve(s, 0, n, t);
    }
};

// Bottom-Up
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (s[0] == '0') return 0;
        vector<int> t(n+1, 0);
        t[n] = 1;
        for(int i=n-1; i>=0; i--) {
            if(s[i]=='0') {
                t[i] = 0;
            } else {
                t[i] = t[i+1];
                if(i+1 <= n-1) {
                    if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))
                    t[i] += t[i+2];
                }
            }
        }
        return t[0];
    }
};
