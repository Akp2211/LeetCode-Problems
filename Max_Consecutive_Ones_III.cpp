#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
            int flips =0,i=0,j=0;
            int maxLen = -1;
            int len;
            while (j<n){
                if(nums[j] == 1) j++;
                else{
                    if(flips<k){
                        flips++;
                        j++;
                    }
                    else{
                        len = j-i;   // calculate length
                        maxLen = max(maxLen,len);
                        while(nums[i] == 1) i++;
                        i++;
                        j++;
                    }
                }
            }
            len = j-i;   // calculate length
              maxLen = max(maxLen,len);
              return maxLen;
        }
    };

int main(){
    return 0;
}