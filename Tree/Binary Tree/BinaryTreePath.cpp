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
    void find(TreeNode *node, string s, vector<string>& ans) {
        if(node==NULL) {
            return;
        }
        if(node->left==NULL && node->right==NULL) {
            s += to_string(node->val);
            ans.push_back(s);
        }
        s += to_string(node->val) + "->";
        if(node->left) {
            find(node->left, s, ans);
        }
        if(node->right) {
            find(node->right, s, ans);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        find(root, s, ans);
        return ans;
    }
};