#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            int sum = 0;
            for(int i = 0; i<n; i++){
                sum = sum + nums[i];
            }
            int miss_no = (n*(n+1))/2 - sum;
        return miss_no;
        }
    };

    int main(){
        return 0;
    }