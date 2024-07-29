#include<bits/stdc++.h>
using namespace std;

//Using BFS
class Solution {
public:
    int ladderLength(string start, string end, vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        int n2 = start.size();
    
        if (st.find(end) == st.end()) {
            return 0;
        }
        
        int count = 0;
        queue<pair<string, int>> q;
        q.push({start, 1});
        st.erase(start); 
        
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if (word == end) {
                return steps;
            }
            
            for (int i = 0; i < n2; ++i) {
                char original = word[i]; 
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == original) continue; 
                    
                    word[i] = c; 
                    
                    if (st.find(word) != st.end()) {
                        st.erase(word); 
                        q.push({word, steps + 1}); 
                    }
                }
                word[i] = original; 
            }
        }
        
        return 0;
    }
};