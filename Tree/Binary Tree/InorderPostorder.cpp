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
    TreeNode *insert(vector<int>& inorder, vector<int>& postorder, int left, int right, int& idx) {
        if(left > right) return nullptr;
        TreeNode *node = new TreeNode(postorder[idx]);
        int pos = search(postorder[idx], inorder);
        idx--;
        node->right = insert(inorder, postorder, pos+1, right, idx);
        node->left = insert(inorder, postorder, left, pos-1, idx);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int idx = n-1;
        return insert(inorder, postorder, 0, n-1, idx);
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
    TreeNode *insert(vector<int>& inorder, vector<int>& postorder, int left, int right, int& idx) {
        if(left > right) return nullptr;
        TreeNode *node = new TreeNode(postorder[idx]);
        int pos = mp[postorder[idx]];
        idx--;
        node->right = insert(inorder, postorder, pos+1, right, idx);
        node->left = insert(inorder, postorder, left, pos-1, idx);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int idx = n-1;
        for(int i=0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        return insert(inorder, postorder, 0, n-1, idx);
    }
};