#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    public:
        int combination(int n,int r =2){
            return (n*(n-1))/2;
        }
        int rev(int n){
            int r =0;
            while(n>0){
                r *= 10;
                r += n%10;
                n /= 10;
            }
            return r;
        }
        int countNicePairs(vector<int>& nums) {
            int n = nums.size();
            int count = 0;
    
            //Brute Force Approach
    
            // for(int i =0; i<n-1; i++){
            //     for(int j=i+1; j<n; j++){
            //         if(nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])) count++;
            //     }
            // }
            // return count++;
            for(int i =0; i<n; i++){
                nums[i] = nums[i] - rev(nums[i]);
            }
            unordered_map<int,int> m;
            for(int ele : nums){
                if(m.find(ele) != m.end()){
                    count = count%1000000007;  // answer too large, return it modulo 10^9 + 7
                    count += m[ele];
                }
                m[ele]++;
            }
            
            return count%1000000007;
        }
};