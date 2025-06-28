#include<iostream>
#include <vector>
#include<climits>
using namespace std;

class Solution {
public:
    //Using Recursion - T.C = O(2^n).
    // Improve using Dp. T.C = O(n*s)
    vector<vector<int>> dp;
    int totalSum;
    int helper(int idx,vector<int>& nums,int sum,int target){
        if(idx == nums.size()){
            if(sum == target) return 1;
            else return 0;
        }
        if(dp[sum+totalSum][idx] != -1) return dp[sum+totalSum][idx];
        int add = helper(idx+1,nums,sum+nums[idx],target);
        int sub = helper(idx+1,nums,sum-nums[idx],target);
        return dp[sum+totalSum][idx] =  add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = 0;
        for(int ele : nums) totalSum += ele;
        dp.resize(2*totalSum+1,vector<int>(nums.size(),-1));
        return helper(0,nums,0,target);

    }
};