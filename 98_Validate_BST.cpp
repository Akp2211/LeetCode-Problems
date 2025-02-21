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
        void inOrder(TreeNode* root,vector<int>& v){
            if(root == NULL) return;
            inOrder(root->left,v);
            v.push_back(root->val);
            inOrder(root->right,v);
        }
    
        bool isValidBST(TreeNode* root) {
            vector<int> v;
            inOrder(root,v);
                for(int j=1; j<=v.size()-1; j++){
                    if(v[j-1] >= v[j]) return false;
                }
            return true;
        }
};