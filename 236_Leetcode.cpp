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
        bool exist(TreeNode* root,TreeNode* target){
            if(root == NULL) return false;
            if(target == root) return true;
            return exist(root->left,target) || exist(root->right,target);   
    
        }
    
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == p || root == q) return root;
            else if(exist(root->left,p) && exist(root->right,q)) return root;
            else if(exist(root->right,p) && exist(root->left,q)) return root;
            else if(exist(root->left,p) && exist(root->left,q)) return lowestCommonAncestor(root->left,p,q);
            else return lowestCommonAncestor(root->right,p,q);
        }
};