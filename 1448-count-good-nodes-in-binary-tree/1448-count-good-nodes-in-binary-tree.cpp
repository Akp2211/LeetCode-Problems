class Solution {
public:
    int solve(TreeNode* root,int count,int currMax){
        if(!root) return 0;
        int curr = 0;
        if(root->val >= currMax){
            curr = 1;
            currMax = root->val;
        }
        int left = solve(root->left,count,currMax);
        int right = solve(root->right,count,currMax);
        return left + right + curr;

    }
    int goodNodes(TreeNode* root) {
        return solve(root,0,root->val);
    }
};