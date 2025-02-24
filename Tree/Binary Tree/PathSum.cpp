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
    bool helper(TreeNode *node, int target, int sum) {
        if(node==NULL) {
            return false;
        }
        sum += node->val;
        if(node->left==NULL && node->right==NULL && sum==target) {
            return true;
        }
        return helper(node->left, target, sum) || helper(node->right, target, sum);
    }
public:
    bool hasPathSum(TreeNode* root, int target) {
        if(root==NULL) {
            return false;
        }
        int sum = 0;
        return helper(root, target, sum);
    }
};