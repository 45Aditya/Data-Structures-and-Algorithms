#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(src==dst) {
            return 0;
        }
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            adj[u].push_back({v,cost}); 
        }
        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0, {src, 0}});
        dist[src] = 0;
        while(!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if(stops==k+1 && node!=dst) {
                continue;
            } else {
                for(auto it : adj[node]) {
                    int v = it.first;
                    int w = it.second;
                    if(w + cost < dist[v]) {
                        dist[v] = w + cost;
                        q.push({stops+1, {v, dist[v]}});
                    }
                }
            }
        }
        return (dist[dst]!=1e9) ? dist[dst] : -1;
    }
};