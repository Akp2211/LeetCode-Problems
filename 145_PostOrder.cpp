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
        void PostOrder(TreeNode* root,vector<int>& v){
            if(root == NULL) return;
            PostOrder(root->left,v);
            PostOrder(root->right,v);
            v.push_back(root->val);
        }
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> post;
            PostOrder(root,post);
            return post;
        }
};