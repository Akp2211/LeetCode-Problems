#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    
        void reversePart(int l,int h,vector<int>&a){
            while(l<h){
            int temp = a[l];
            a[l] = a[h];
            a[h] = temp;
            l++;
            h--;
            }
        }
    
        void rotate(vector<int>& nums, int k) {
             int n = nums.size();
        if(k>n) k = k%n;
        reversePart(0,n-k-1,nums);
        reversePart(n-k,n-1,nums);
        reversePart(0,n-1,nums);
    
        return;
        }
    };

int main(){
    return 0;
}