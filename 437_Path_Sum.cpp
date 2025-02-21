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
        void helper(TreeNode* root,long long tar,int& count){
            if(root == NULL) return;
            if((long long)(root->val) == tar) count++;
            tar = tar - (long long)(root->val);
            helper(root->left,tar,count);
            helper(root->right,tar,count);
        }
    
        int pathSum(TreeNode* root, int targetSum) {
            if(root == NULL) return 0;
            int count = 0;
            helper(root,(long long)targetSum,count);
            count += (pathSum(root->left,targetSum) + pathSum(root->right,targetSum));
            return count;
        }
};