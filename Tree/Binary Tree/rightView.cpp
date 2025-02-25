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
    void helper(TreeNode *node, vector<int>& ans, int level){
        if(node==NULL) return;
        if(level==ans.size()) ans.push_back(node->val);
        helper(node->right, ans, level+1);
        helper(node->left, ans, level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root, ans, 0);
        return ans;
    }
};
