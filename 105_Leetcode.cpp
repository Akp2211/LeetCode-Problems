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
        TreeNode* build(vector<int>& pre,int preLow,int preHi, vector<int>& in,int inLow,int inHi){
            if(preLow > preHi) return NULL;
            TreeNode* root = new TreeNode(pre[preLow]);
            if(preLow == preHi) return root;
            int i = inLow;
            while(i<=inHi){
                if(in[i] == pre[preLow]) break;
                i++;
            } 
            int leftCount = i - inLow;
            int rightCount = inHi - i;
            root->left = build(pre,preLow+1,preLow+leftCount,in,inLow,i-1);
            root->right = build(pre,preLow+1+leftCount,preHi,in,i + 1,inHi);
            return root;
        }
        TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
            int n = pre.size();
            return build(pre,0,n-1,in,0,n-1);
        }
};