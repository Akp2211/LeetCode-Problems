#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
            int n = nums.size();
            sort(nums.begin(),nums.end());  // Sort the nums.
            int sum = 0;
            for(int i =0; i<n; i++){  // prefix Sum Stored in nums only
                sum = sum + nums[i];
                nums[i] = sum;
            }
            int m = queries.size();
            vector<int> ans(m);  //This will Store answer
            for(int i =0; i<m; i++){
                int val = 0;         // val store value that will stored in ans.
    
                //Binary Search
                int low = 0;
                int high = n-1;
                while(low<=high){
                    int mid = low + (high-low)/2;
                    if(nums[mid]>queries[i]) high = mid - 1;
                    else{
                        val = mid + 1;
                        low = mid+1;
                    }
                }
                ans[i] = val;
            }
            return ans;
        }
    };

int main(){
    return 0;
}