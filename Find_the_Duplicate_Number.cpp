#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int n = nums.size();
            int i = 0;
            while(i<n){
              int correctidx = nums[i];
              if(nums[correctidx] == nums[i]) return nums[i];
              else swap(nums[i],nums[correctidx]);
            }
            return 0;
        }
    };

    int main(){
        return 0;
    }