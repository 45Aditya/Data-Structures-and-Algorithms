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
    void calculate(TreeNode *node, int& sum) {
        if(node==NULL) {
            return;
        }
        if(node->left) {
            if(node->left->left==NULL && node->left->right==NULL) {
                sum += node->left->val;
            } else {
                calculate(node->left, sum);
            }
        }
        if(node->right) {
            calculate(node->right, sum);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int sum = 0;
        calculate(root, sum);
        return sum;
    }
};