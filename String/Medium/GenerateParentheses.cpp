#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void generate(int open, int close, vector<string>& ans, string s) {
        if(open==0 && close==0) {
            ans.push_back(s);
            return;
        } 
        if(open!=0) {
            string s1 = s;
            s1 += '(';
            generate(open-1, close, ans, s1);
        }
        if(close > open) {
            string s2 = s;
            s2 += ')';
            generate(open, close-1, ans, s2);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> ans;
        string s = "";
        generate(open, close, ans, s);
        return ans;
    }
};