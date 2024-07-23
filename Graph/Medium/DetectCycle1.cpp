#include<bits/stdc++.h>
using namespace std;

//Using BFS
class Solution {
    bool bfs(int v, vector<int> adj[], vector<int>& visit, int node) {
        visit[node] = 1;
        queue<pair<int,int>> q;
        q.push({node, -1});
        while(!q.empty()) {
            int child = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto node : adj[child]) {
                if(!visit[node]) {
                    visit[node] = 1;
                    q.push({node, child});
                } else if(node!=parent){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visit(V,0);
        for(int i=0; i<V; i++) {
            if(!visit[i]) {
                if(bfs(V, adj, visit, i)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//Using DFS
class Solution {
    bool dfs(int v, vector<int> adj[], vector<int>& visit, int node, int start) {
        visit[node] = 1;
        int child = node;
        int parent = start;
        for(auto node : adj[child]) {
            if(!visit[node]) {
                visit[node] = 1;
                if(dfs(v, adj, visit, node, child)) {
                    return true;
                }
            } else if(node!=parent) {
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visit(V,0);
        for(int i=0; i<V; i++) {
            if(!visit[i]) {
                if(dfs(V, adj, visit, i, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};