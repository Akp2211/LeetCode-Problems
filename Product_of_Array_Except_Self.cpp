#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(n); 
            int p = 1;
            ans[0] = 1;
            for(int i =1; i<n; i++){
                p = p*nums[i-1];
                ans[i] = p;
            }
            p = 1;
            for(int i = n-1; i>=0; i--){
                int a = nums[i];
                nums[i] = p;
                p = p*a;
            }
            for(int i = 0; i<n; i++){
                ans[i] = ans[i]*nums[i];
            }
            return ans;
        }
    };

    int main(){
        return 0;
    }