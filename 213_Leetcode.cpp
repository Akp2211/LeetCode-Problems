#include<iostream>
#include <vector>
#include<climits>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];
        // array to store the maximum loot
        vector<int> dp(nums.size(),0);
        // Memoize maximum loots at first 2 indexes
        dp[0] = nums[0];
        if(nums.size() != 1) dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size()-1; i++) {
            // Core logic
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int max1 = dp[nums.size()-2];
        dp.clear();
        dp.resize(nums.size(),0);
         // Memoize maximum loots at first 2 indexes
        dp[1] = nums[1];
        if(nums.size() != 2) dp[2] = max(nums[1], nums[2]);
        for (int i = 3; i < nums.size(); i++) {
            // Core logic
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int max2 = dp[nums.size()-1];
        return max(max1,max2);
    }
};