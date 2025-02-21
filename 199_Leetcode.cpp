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
        int levels(TreeNode* root){
            if(root == NULL) return 0;
            return 1 + max(levels(root->left),levels(root->right));
        }
    
        void nthOrder(TreeNode* root,int curr,int level,vector<int>& ans){
            if(root == NULL) return;
            if(curr == level){
                ans[level] = root->val;
            }
            nthOrder(root->left,curr+1,level,ans);
            nthOrder(root->right,curr+1,level,ans);
        }
    
        vector<int> rightSideView(TreeNode* root) {
            int n = levels(root);
            vector<int> ans(n);
            for(int i=0; i<n; i++){
                nthOrder(root,0,i,ans);
            }
            return ans;
        }
};