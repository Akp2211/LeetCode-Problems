#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            if(n == 1){
                if(nums[n-1] == target) return 0;
                else return -1;
            }
            else if(n == 2){
                if(target == nums[0]) return 0;
                else if (target == nums[1]) return 1;
                else return -1;
            }
            else{
             int low = 0;
            int high = n-1;
            int pivot = -1; 
            // Finding the pivot element/index.
            while(low<=high){
                int mid = low + (high-low)/2;
                if(mid == 0){ pivot = mid + 1;
                break;}
                else if(mid == high){ pivot = mid - 1;
                break;}
                else{
                 if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]){
                    pivot = mid;
                    break;
                 }
                 if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                    pivot = mid+1;
                    break;
                 }
                 else if(nums[mid]>nums[high]) low = mid + 1;
                 else high = mid - 1;
                 }
            }
            cout<<pivot;
            // if array is not rotated i.e k=0
            if(pivot == -1){
             low = 0;
             high = n - 1;
             while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            }
            // searching in two array divided by pivot
             else{
             if(target>=nums[0] && target<=nums[pivot-1]){
             low = 0;
             high = pivot - 1;
             while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            }
             
            else{
                low = pivot;
             high = n-1;
                while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) high = mid - 1;
                else low = mid + 1;
                }
            }
             }
            
            }
            return -1;
        }
    };
    
int main(){
    return 0;
}