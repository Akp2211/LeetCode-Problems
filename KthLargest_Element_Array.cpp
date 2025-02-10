#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size();
            sort(nums.begin(),nums.end());
            return nums[n-k];
    
            //Method -2
            // priority_queue<int, vector<int>, greater<int>> pq;  //Min Heap.  
            // for(int i=0; i<n; i++){
            //     pq.push(nums[i]);
            //     if(pq.size() > k) pq.pop();
            // }
            // return pq.top();
        }
    };

int main(){
    return 0;
}    