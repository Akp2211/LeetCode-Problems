#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
    public:
        int reverse(int n){
            int r =0;
            while(n>0){
                r = r*10;
                r = r + (n%10);
                n = n/10;
            }
            return r;
        }
        
        int countDistinctIntegers(vector<int>& nums) {
            unordered_set<int> s;
            for(int i=0; i<nums.size(); i++){
                int rev = reverse(nums[i]);
                s.insert(rev);
                s.insert(nums[i]);
            }
            return s.size();
        }
};