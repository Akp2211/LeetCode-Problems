#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //Dynamic programming using tabulation method.
        for (int i = 2; i < n; i++) {
            cost[i] += min(cost[i - 1],cost[i - 2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};