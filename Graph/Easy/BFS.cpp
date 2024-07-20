#include<bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(int node, int V, vector<int> adj[], vector<int>& visit, vector<int>& ans) {
        queue<int> q;
        q.push(node);
        visit[node] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(!visit[it]) {
                    q.push(it);
                    visit[it] = 1;
                }
            }
            ans.push_back(node);
        }
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visit(V,0);
        vector<int> ans;
        for(int i=0; i<V; i++) {                // for connected component
            if(!visit[i]) {
                bfs(i, V, adj, visit, ans);
            }
        }
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);  //adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}