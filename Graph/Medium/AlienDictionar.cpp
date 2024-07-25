#include<bits/stdc++.h>
using namespace std;

//Using Topo Sort
class Solution {
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> inDeg(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                inDeg[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto it : adj[node]) {
                inDeg[it]--;
                if (inDeg[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (ans.size() != V) {
            return {};
        }
        return ans;
    }
public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(K, adj);
        if (topo.empty()) {
            return "";
        }
        string ans = "";
        for (auto it : topo) {
            ans += char(it + 'a');
        }
        return ans;
    }
};