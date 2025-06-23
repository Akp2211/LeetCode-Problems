#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;
    bool helper(int idx,vector<int>& nums){
        if(idx >= nums.size() -1) return true;
        if(dp[idx] != -1) return dp[idx];
        bool flag = false;
        if(nums[idx] >= nums.size()-1-idx) return true;
        for(int i=1; i<=nums[idx]; i++){
            flag = flag || helper(idx+i,nums);
            if(flag) break;
        }
        return dp[idx] = flag;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return helper(0,nums);
    }
};