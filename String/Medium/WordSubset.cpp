#include<bits/stdc++.h>
using namespace std;

//Brute Force
class Solution {
    void solve(string& s, int idx, set<string>& st, string str) {
        if(idx>=s.length()) {
            sort(str.begin(), str.end());
            st.insert(str);
            return;
        }
        str += s[idx];
        solve(s, idx+1, st, str);
        str.pop_back();
        solve(s, idx+1, st, str);
        return;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int n = words1.size();
        int m = words2.size();
        unordered_map<string, set<string>> mp;
        for(int i=0; i<n; i++) {
            set<string> st;
            solve(words1[i], 0, st, "");
            mp[words1[i]] = st;
        }
        for(int i=0; i<n; i++) {
            set<string> st = mp[words1[i]];
            bool flag = true;
            for(int j=0; j<m; j++) {
                string s = words2[j];
                sort(s.begin(), s.end());
                if(st.find(s)==st.end()) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(words1[i]);
        }
        return ans;
    }
};

//optimal
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        char freq[26] = {0};
        for(int i=0; i<words2.size(); i++) {
            char temp[26] = {0};
            for(auto c : words2[i]) {
                temp[c-'a']++;
            }
            for(int i=0; i<26; i++) {
                freq[i] = max(freq[i], temp[i]);
            }
        }
        vector<string> ans;
        for(int i=0; i<words1.size(); i++) {
            char mp[26] = {0};
            bool flag = true;
            for(auto c : words1[i]) {
                mp[c-'a']++;
            }
            for(int i=0; i<26; i++) {
                if(freq[i] > mp[i]) {  
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};