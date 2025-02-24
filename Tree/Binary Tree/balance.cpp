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
    int height(TreeNode *node, bool& balance) {
        if(node==NULL) return 0;
        int left = height(node->left, balance);
        int right = height(node->right, balance);
        if(abs(right-left) >= 2) balance = false;
        return 1 + max(right, left); 
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        bool balance = true;
        height(root, balance);
        return balance;
    }
};