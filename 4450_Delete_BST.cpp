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
       TreeNode* inOrderPred(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right != NULL){
            pred = pred->right;
        }
        return pred;
    }
    
    //Delete Node of BST.
    TreeNode* deleteNode(TreeNode* root,int key){
        if(root == NULL) return NULL;
        if(root->val == key){
            //Leaf Node.
            if(root->left == NULL && root->right == NULL) return NULL;
    
            //One Child.
            else if(root->left == NULL || root->right == NULL) {
                if(root->left != NULL) return root->left;
                else return root->right;
            }
    
            //Two Child.
            else {
                TreeNode* pred = inOrderPred(root);
                root->val = pred->val;
                root->left = deleteNode(root->left,pred->val);
            }
    
        } 
        else if(root->val > key){  //Go left
             root->left = deleteNode(root->left,key);
        }
        else root->right = deleteNode(root->right,key); //Go right.
        return root;
    }
};