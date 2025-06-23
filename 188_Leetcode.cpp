#include<iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    int dp[1001][101][2]; //3D Array to remove TLE.
    int n;
    int f(vector<int>& prices,int k,int i,bool ongoing_tran){
        if(i==n) return 0;
        if(dp[i][k][ongoing_tran] != -1) return dp[i][k][ongoing_tran]; 
        int ans = INT_MAX;
        ans = f(prices,k,i+1,ongoing_tran); //Avoid ith stock
        if(ongoing_tran){
             ans = max(ans,f(prices,k-1,i+1,false) + prices[i]);  //sell stock
        }
        else{
            if(k>0){
                ans = max(ans,f(prices,k,i+1,true) - prices[i]);//Buy ith stock.
            }
        }
        return dp[i][k][ongoing_tran] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof dp);
        return f(prices,k,0,false);
    }
};