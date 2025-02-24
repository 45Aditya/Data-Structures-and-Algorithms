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
    int solve(TreeNode *node, int& sum) {
        if(node==NULL) return 0;
        int left = max(0, solve(node->left, sum));
        int right = max(0, solve(node->right, sum));
        sum = max(sum, node->val + left + right);
        return node->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int sum = -1e9;
        solve(root, sum);
        return sum;
    }
};