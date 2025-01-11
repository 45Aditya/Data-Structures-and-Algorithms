#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n<k) return false;
        if(n==k) return true;
        char freq[26] = {0};
        for(auto c : s) {
            freq[c-'a']++;
        }
        int cnt = 0;
        for(int i=0; i<26; i++) {
            if(freq[i]%2!=0) cnt++;
        }
        if(cnt <= k) return true;
        return false;
    }
};