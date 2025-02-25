#include<bits/stdc++.h>
using namespace std;


//Using DFS
class Solution {
    void dfs(Node *node, map<int,pair<int,int>>& mp, int hd, int level) {
        if(node==NULL) return;
        if(mp.find(hd)==mp.end() || mp[hd].second <= level) {
            mp[hd] = {node->data, level};
        } 
        dfs(node->left, mp, hd-1, level+1);
        dfs(node->right, mp, hd+1, level+1);
    }
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int,pair<int,int>> mp;
        dfs(root, mp, 0, 0);
        for(auto it : mp) {
            ans.push_back(it.second.first);
        }
        return ans;
    }
};