#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp; //use to memomize
    int helper(string& s1,string& s2,int i,int j){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = helper(s1,s2,i-1,j-1);
        else{
            int add = 1 + helper(s1,s2,i,j-1); //insert
            int remove = 1 + helper(s1,s2,i-1,j); //delete
            int replace = 1 + helper(s1,s2,i-1,j-1); //replace
            return dp[i][j] = min(add,min(remove,replace));
        }
    } 

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        dp.resize(m,vector<int>(n,-1));
        return helper(word1,word2,m-1,n-1);
    }
};