#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        void sortColors(vector<int>& nums) {
         int n = nums.size();
         int noo = 0;
         int noz = 0;   
         int notw = 0; 
         for(int i =0; i<n; i++){
            if(nums[i] == 0) noz++;
            else if(nums[i] == 1) noo++;
            else notw++;
         }  
         // fills 
         for(int i = 0; i<n; i++){
            if(i<noz) nums[i] = 0;
            else if(i<(noo+noz)) nums[i] = 1;
            else{
                nums[i] = 2;
            }
         }
        return;
        }
    };

int main(){
    return 0;
}