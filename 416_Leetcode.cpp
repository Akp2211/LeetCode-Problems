#include<iostream>
#include <vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    bool helper(int i,vector<int>& arr,int sum,int target){
        if(i == arr.size()){
            if(sum == target) return true;
            else return false;
        }
        if(sum == target) return dp[i][sum] = true;
        if(dp[i][sum] != -1) return dp[i][sum];
         if(sum + arr[i] > target) return dp[i][sum] = helper(i+1,arr,sum,target); //leave the element
         int take = helper(i+1,arr,sum+arr[i],target);
         int leave = helper(i+1,arr,sum,target);
         return dp[i][sum] = take || leave;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i =0; i<n; i++) totalSum += nums[i];
        if(totalSum % 2 != 0) return false;
        dp.resize(n,vector<int>(totalSum/2+1,-1));
        return helper(0,nums,0,totalSum/2);
    }
};