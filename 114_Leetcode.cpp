#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr),right(nullptr) {}
    TreeNode(int x, TreeNode *left,TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        //Method-1
    
        // void preOrder(TreeNode* root,vector<TreeNode*>& ans){
        //     if(root == NULL) return;
        //     ans.push_back(root);
        //     preOrder(root->left,ans);
        //     preOrder(root->right,ans);
        // }
    
        // void flatten(TreeNode* root) {
        //     vector<TreeNode*> ans;
        //     preOrder(root,ans);
        //     int n = ans.size();
        //     for(int i =0; i<n-1; i++){
        //         ans[i]->right = ans[i+1];
        //         ans[i]->left = NULL;  //make Left NULL.
        //     }
    
        //Method-2
        void flatten(TreeNode* root){
            if(root == NULL) return;
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            root->left = NULL;
            root->right = NULL;
            flatten(l);
            flatten(r);
            root->right = l;
            TreeNode* temp = root;
            while(temp->right != NULL) temp = temp->right;
            temp->right = r;
        }
};