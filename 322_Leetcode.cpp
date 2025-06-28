#include<iostream>
#include <vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;//Memoizise.
    int helper(int idx,vector<int>& coins, int amount){
        if(idx == coins.size()){
            if(amount == 0) return 0;
            else return INT_MAX;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        if(amount - coins[idx] < 0 ) return dp[idx][amount] = helper(idx+1,coins,amount); //leave
        long long take = 1LL + helper(idx,coins,amount-coins[idx]); //Type cast 1 to long long
        long long leave = helper(idx+1,coins,amount);
        return dp[idx][amount] = min(take,leave);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        int ans =  helper(0,coins,amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};