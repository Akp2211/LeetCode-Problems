#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Method - 1
    // int fibo(int n){
    //     if(n == 0 || n == 1) return n;
    //     return fibo(n-1) + fibo(n-2);
    // }

    //Method - 2 : Using memoization.
    int fibo(vector<int>& dp,int n){
        if(n<= 1) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = fibo(dp,n-1) + fibo(dp,n-2);
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fibo(dp,n);
    }
};