#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});
        int maxi = -1e9;
        while(!q.empty()) {
            int l = q.front().second;
            int r = q.front().second;
            int n = q.size();
            maxi = max(maxi, (int)r-l+1);
            for(int i=0; i<n; i++) {
                TreeNode *node = q.front().first;
                int idx = q.front().second;
                q.pop();
                if(node->left) q.push({node->left, 2*idx + 1});
                if(node->right) q.push({node->right, 2*idx + 2});
            }
        }
        return maxi;
    }
};