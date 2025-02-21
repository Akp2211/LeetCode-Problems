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
        TreeNode* build(vector<int>& in,int inLow,int inHi,vector<int>& post,int postLow,int postHi){
            if(postLow > postHi) return NULL;
            TreeNode* root = new TreeNode(post[postHi]);
            if(postLow == postHi) return root;
            int i = inLow;
            while(i<=inHi){
                if(in[i] == post[postHi]) break;
                i++;
            }
            int leftCount = i - inLow;
            int rightCount = inHi - i;
            root->left = build(in,inLow,i-1,post,postLow,postLow+leftCount-1);
            root->right = build(in,i+1,inHi,post,postLow+leftCount,postHi-1);
            return root;
        }
    
        TreeNode* buildTree(vector<int>& in, vector<int>& post) {
            int n = post.size();
            return build(in,0,n-1,post,0,n-1);
        }
};