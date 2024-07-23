#include<bits/stdc++.h>
using namespace std;

//Using DFS
class Solution
{
    void helper(int v, vector<int> adj[], vector<int>& visit, stack<int>& st, int node) {
        visit[node] = 1;
        for(auto it : adj[node]) {
            if(!visit[it]) {
                helper(v, adj, visit, st, it);
            }
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int> visit(v,0);
	    stack<int> st;
	    for(int i=0; i<v; i++) {
	        if(!visit[i]) {
	            helper(v, adj, visit, st, i);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty()) {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

//Using BFS [Kahn's Algo]
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int> deg(v,0);
	    for(int i=0; i<v; i++) {
	        for(auto it : adj[i]) {
	            deg[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0; i<v; i++) {
	        if(deg[i]==0) {
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()) {
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	        for(auto it : adj[node]) {
	            deg[it]--;
	            if(deg[it]==0) {
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	}
};