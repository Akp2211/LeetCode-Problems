#include<iostream>
#include<vector>
using namespace std;

class Solution {
public: 
    vector<vector<vector<double>>> dp; //define a 3D vector.
    double helper(int i,int j,int k,int n){
        if(i<0 || j<0 || i>n-1 || j>n-1) return 0;
        if(k == 0) return 1;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int dx[8] = {1,2,-1,-2,1,2,-1,-2}; 
        int dy[8] = {2,1,-2,-1,-2,-1,2,1};
        double prob = 0;
        for(int a = 0; a<8; a++){
            prob += helper(i+dx[a],j+dy[a],k-1,n) * (0.125);
        }
        return dp[i][j][k] = prob;
    }
    double knightProbability(int n, int k, int row, int column) {
        dp = vector<vector<vector<double>>>(
            n, vector<vector<double>>(
                n, vector<double>(k+1, -1)
            )
        );
        return helper(row,column,k,n);
    }
};