#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
    public:
        int matrixSum(vector<vector<int>>& nums) {
                int score = 0;
        
        while (!nums.empty()) {
            vector<int> maxInRow;
    
            for (auto& row : nums) {
                if (!row.empty()) {
                    auto maxIt = max_element(row.begin(), row.end());
                    maxInRow.push_back(*maxIt);
                    row.erase(maxIt);  
                }
            }
      
            int maxVal = *max_element(maxInRow.begin(), maxInRow.end());
    
            score += maxVal;
            
            nums.erase(remove_if(nums.begin(), nums.end(), [](const vector<int>& row) { return row.empty(); }), nums.end());
        }
        return score;
        }
    };
    
int main(){
    return 0;
}    