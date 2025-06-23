#include<iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_price = INT_MAX;
        int max_profit = 0;
        for(int i= 0; i<n; i++){
            if(prices[i] < min_price) min_price = prices[i]; //Buy stock
            int profit = prices[i] - min_price;
            if(profit > max_profit) max_profit = profit; //Sell stock
        }
        return max_profit;
    }
};