#include<iostream>
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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            //Base case
            if(p == NULL && q == NULL) return true;
            else if((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
    
            if(p->val != q->val) return false;
    
            bool LST = isSameTree(p->left,q->left);
            if(!LST) return false;
    
            bool RST = isSameTree(p->right,q->right);
            if(!RST) return false;
            
            return true;
    
        }
};