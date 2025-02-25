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
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            if(!root) return ans;
            deque<TreeNode*> dq;
            dq.push_front(root);
            int level = 1;
            while(!dq.empty()){
                int n = dq.size();
                vector<int> temp;
                for(int i=0; i<n; i++){
                    if(level%2 != 0){
                        TreeNode *node = dq.front();
                        dq.pop_front();
                        temp.push_back(node->val);
                        if(node->left!=NULL) dq.push_back(node->left);
                        if(node->right!=NULL) dq.push_back(node->right);   
                    }
                    else{
                        TreeNode *node = dq.back();
                        dq.pop_back();
                        temp.push_back(node->val);
                        if(node->right!=NULL) dq.push_front(node->right);
                        if(node->left!=NULL) dq.push_front(node->left);
                    }
                    
                }
                level++;
                ans.push_back(temp);
            }
            return ans;
        }
    };