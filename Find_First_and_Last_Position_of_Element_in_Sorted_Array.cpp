#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> v;
            int low = 0;
            int high = nums.size()-1;
            int idx = -1;
            //first occurence
            while(low<=high){
                int mid = (low+high)/2;
                if(nums[mid] == target){
                    if(mid == 0 || nums[mid-1] != target){
                        idx = mid;
                        break;
                    }
                    else high = mid - 1;
                }
                if(nums[mid] < target) low = mid + 1;
                if(nums[mid] > target) high = mid - 1;
            }
            v.push_back(idx);
             low = 0;
             high = nums.size()-1;
             idx = -1;
            //last occurence
            while(low<=high){
                int mid = (low+high)/2;
                if(nums[mid] == target){
                    if(mid == nums.size()-1 || nums[mid+1] != target){
                        idx = mid;
                        break;
                    }
                    else low = mid + 1;
                }
                if(nums[mid] < target) low = mid + 1;
                if(nums[mid] > target) high = mid - 1;
            }
            v.push_back(idx);
            return v;
        }
    };

int main(){
    return 0;
}    