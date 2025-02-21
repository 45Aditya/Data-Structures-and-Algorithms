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
    bool helper(TreeNode *node1, TreeNode *node2) {
        if(node1==NULL && node2==NULL) {
            return true;
        }
        if((node1!=NULL && node2!=NULL) && (node1->val==node2->val)) {
            return helper(node1->left, node2->left) && helper(node1->right, node2->right);
        } else {
            return false;
        }
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if((p!=NULL && q!=NULL) && (p->val==q->val)) {
            return helper(p->left, q->left) && helper(p->right, q->right);
        } 
        return false;
    }
};