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

 void helper(TreeNode* root, int& count){
    if(root==NULL){
        return;
    }
    if(root){
        count++;
    }
    helper(root->left, count);
    helper(root->right, count);
    return;
}

class Solution {
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        helper(root, count);
        return count;
    }
};