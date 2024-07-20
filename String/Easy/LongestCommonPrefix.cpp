#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(), str.end());
        int n = str.size();
        string s1 = str[0];
        string s2 = str[n-1];
        int len = min(s1.size(), s2.size());
        string s = "";
        for(int i=0; i<len; i++) {
            if(s1[i]==s2[i]) {
                s += s1[i];
            } else {
                break;
            }
        }
        return s;
    }
};