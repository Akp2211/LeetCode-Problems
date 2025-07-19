#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dp; //top down dp
    int f(int n){
        if(n==0 || n == 1) return 1;
        if(n==2) return 2;
        if (dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 1; i<=n; i++){
            // i as a potential root.
            ans += f(i-1) * f(n-i);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        dp.clear();
        dp.resize(20,-1);
        return f(n);
    }
};