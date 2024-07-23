#include<bits/stdc++.h>
using namespace std;

//Using BFS
class Solution {
    bool dfs(int v, vector<int> adj[], vector<int>& visit, vector<int>& pathVisit, vector<int>&safe, int node) {
        visit[node] = 1;
        pathVisit[node] = 1;
        safe[node] = 0;
        for(auto it : adj[node]) {
            if(!visit[it]) {
                if(dfs(v, adj, visit, pathVisit, safe, it)) {
                    return true;
                }
            } else if(pathVisit[it]) {
                return true;
            }
        }
        pathVisit[node] = 0;
        safe[node] = 1;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        vector<int> visit(v,0);
        vector<int> pathVisit(v,0);
        vector<int> safe(v,0);
        for(int i=0; i<v; i++) {
            if(!visit[i]) {
                dfs(v, adj, visit, pathVisit, safe, i);
            }
        }
        vector<int> ans;
        for(int i=0; i<v; i++) {
            if(safe[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};