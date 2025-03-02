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
    int search(int val, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) {
            if(inorder[i]==val) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* insert(vector<int>& preorder, vector<int>& inorder, int left, int right, int& idx) {
        if(left > right) return nullptr;
        TreeNode *node = new TreeNode(preorder[idx]);
        int pos = search(preorder[idx], inorder);
        idx++;
        node->left = insert(preorder, inorder, left, pos-1, idx);
        node->right = insert(preorder, inorder, pos+1, right, idx);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        TreeNode *root = insert(preorder, inorder, 0, n-1, idx);
        return root;
    }
};


//Using Map
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
    map<int,int> mp;
    TreeNode* insert(vector<int>& preorder, vector<int>& inorder, int left, int right, int& idx) {
        if(left > right) return nullptr;
        TreeNode *node = new TreeNode(preorder[idx]);
        int pos = mp[preorder[idx]];
        idx++;
        node->left = insert(preorder, inorder, left, pos-1, idx);
        node->right = insert(preorder, inorder, pos+1, right, idx);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        for(int i=0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        TreeNode *root = insert(preorder, inorder, 0, n-1, idx);
        return root;
    }
};