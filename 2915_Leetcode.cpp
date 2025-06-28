#include<iostream>
#include <vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int helper(int idx,vector<int>& nums,int sum,int target){
        if(sum == target) return 0;
        if(idx>= nums.size() || sum>target) return INT_MIN;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int take = 1 + helper(idx+1,nums,sum+nums[idx],target);
        int leave = helper(idx+1,nums,sum,target);
        return dp[idx][sum] = max(take,leave);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        dp.resize(nums.size()+1,vector<int>(target+1,-1));
        int ans = helper(0,nums,0,target);
        if(ans<0) return -1;
        return ans;
    }
};