#include<iostream>
#include<vector>
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
        void helper(TreeNode* root,vector<int> v,vector<vector<int>>& ans,int tar){
            if(root == NULL) return;
            if(root->left == NULL && root->right == NULL){
                if(root->val == tar){
                    v.push_back(root->val);
                    ans.push_back(v);
                }
                return;
            }
            tar = tar - root->val;
            v.push_back(root->val);
            helper(root->left,v,ans,tar);
            helper(root->right,v,ans,tar);
        }
    
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<vector<int>> ans;
            vector<int> v;
            helper(root,v,ans,targetSum);
            return ans;
    
        }
};