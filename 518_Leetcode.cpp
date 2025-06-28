#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int helper(int idx,int amount,vector<int>& coins){
        if(amount == 0) return 1;
        if(amount < 0 ) return 0;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int totalWays = 0;
        for(int i =idx; i< coins.size(); i++) {
            totalWays += helper(i,amount-coins[i],coins);
        }
        return dp[idx][amount] = totalWays;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return helper(0,amount,coins);
    }
};