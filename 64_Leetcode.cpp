#include<iostream>
#include <vector>
#include<climits>
using namespace std;

class Solution {
public:
    int n,m;
    vector<vector<int>> arr,dp;
    int f(int i,int j){
        if(i== n-1 && j == m-1) return arr[n-1][m-1];
        if(i>=n || j>=m) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = arr[i][j] + min(f(i+1,j),f(i,j+1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        arr = grid;
        n = grid.size();
        m = grid[0].size();
        dp.clear();
        dp.resize(n,vector<int>(m,-1));
        // return f(0,0);
        
        //Solve using Tabulation
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if(i==0) dp[i][j] = grid[i][j] + dp[0][j-1];
                else if(j==0) dp[i][j] = grid[i][j] + dp[i-1][0];
                else dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
                cout<<dp[i][j]<<" ";
            }
        }
        return dp[n-1][m-1];
    }
};