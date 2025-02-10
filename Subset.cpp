#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
class Solution {
    public:
        void helper(vector<int>& nums,vector<int>ans,vector<vector<int>> &V,int idx){
            if(idx == nums.size()) {
                V.push_back(ans);
                return;
            }
            int check = nums[idx];
            helper(nums,ans,V,idx+1);
            ans.push_back(check);
            helper(nums,ans,V,idx+1);
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans;
            vector<vector<int>> V;
            helper(nums,ans,V,0);
    
           return V;
        }
    };

int main(){
    return 0;
}    