#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int n = nums.size();
            int i =0;
            int j = 0;
            int sum = 0;
            int minLen = n+1;
            int len;
            while(j<n){
                sum += nums[j];
                while(sum>=target){
                    len = j-i+1;
                    minLen = min(len,minLen);
                    sum -= nums[i];
                    i++;
                }
                j++;
            }
            if(sum<target && minLen ==n+1){
                 return 0;
            }
            return minLen;
        }
    };

int main(){
    return 0;
}