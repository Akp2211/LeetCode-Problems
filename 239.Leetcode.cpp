#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;
        int n = nums.size();
    
        //solution using stack.
    
        // int ngi[n];  //Array of next greater element's index
        // stack <int> s;
        // ngi[n-1] = n;
        // s.push(n-1);
        // for(int i =n-2; i>=0; i--){
        //     while(s.size()>0 && arr[s.top()]<= arr[i]) s.pop();
        //     if(s.size() ==0 ) ngi[i] = n;
        //     else ngi[i] = s.top();
        //     s.push(i);
        // }
        // vector<int>ans;
        // int j = 0;
        // for(int i =0; i<n-k+1; i++){
        //     if(j<i) j = i;
        //     int mx = arr[i];
        //     while(j < i+k){  //means nge is inside the window.
        //        mx = arr[j];
        //        if(ngi[j] >= i+k) break; 
        //        j = ngi[j];
        //     }
        //     ans.push_back(mx);
        // }
    
        //Solve using Dequeue
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<n; i++){
            while(dq.size() > 0 && nums[i] > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            int j = i-k+1;  //start of the window
            while(dq.front() < j) dq.pop_front();
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
        }
};