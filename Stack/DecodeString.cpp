#include<bits/stdc++.h>
using namespace std;

class Solution {
    string helper(int &idx, string s) {
        int n = 0;
        string str = "";
        while (idx < s.size()) {
            char c = s[idx];
            if (c >= '0' && c <= '9') {
                n = n * 10 + (c - '0');
            } else if (c == '[') {
                idx++; // Skip '['
                string temp = helper(idx, s);
                //idx++; // Skip ']'
                while (n > 0) {
                    str += temp;
                    n--;
                }
            } else if (c == ']') {
                return str;
            } else {
                str += c;
            }
            idx++;
        }
        return str;
    }

public:
    string decodeString(string s) {
        int i = 0;
        return helper(i, s);
    }
};