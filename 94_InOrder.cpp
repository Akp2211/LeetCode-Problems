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
        void InOrder(TreeNode* root,vector<int>& v){
            if(root == NULL) return;
            InOrder(root->left,v);
            v.push_back(root->val);
            InOrder(root->right,v);
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> in;
            InOrder(root,in);
            return in;
        }
};