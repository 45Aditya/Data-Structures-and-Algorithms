#include<bits/stdc++.h>
using namespace std;

// Problem Without It:
// If a deeper node (higher level value) is stored first for a given hd, the actual topmost node (shallower level) won't be able to replace it.

// What the Second Condition Does:
// Ensures that only the topmost (smallest level) node at each horizontal distance (hd) is stored.


//Using DFS
class Solution {
    void dfs(Node *node, map<int, pair<int,int>>& mp, int hd, int level) {
        if(node==NULL) return;
        if(mp.find(hd)==mp.end() || mp[hd].second > level) {
            mp[hd] = {node->data, level};
        }
        dfs(node->left, mp, hd-1, level+1);
        dfs(node->right, mp, hd+1, level+1);
    }
    
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int, pair<int,int>> mp;
        dfs(root, mp, 0, 0);
        for(auto it : mp) {
            ans.push_back(it.second.first);
        }
        return ans;
    }
};


//Using BFS
class Solution {
    
    void bfs(Node *node, map<int, pair<int,int>>& mp) {
        queue<pair<Node*, pair<int,int>>> q;
        q.push({node, {0, 0}});
        while(!q.empty()) {
            int n = q.size();
            for(int i=0; i<n; i++) {
                Node *node = q.front().first;
                int hd = q.front().second.first;
                int level = q.front().second.second;
                q.pop();
                if(mp.find(hd)==mp.end() || mp[hd].second > level) {
                    mp[hd] = {node->data, level};
                }
                if(node->left) q.push({node->left, {hd-1, level+1}});
                if(node->right) q.push({node->right, {hd+1, level+1}});
            }
        }
    }
    
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int, pair<int,int>> mp;
        bfs(root, mp);
        for(auto it : mp) {
            ans.push_back(it.second.first);
        }
        return ans;
    }
};