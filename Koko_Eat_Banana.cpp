#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    public:
        bool check(int mid,vector<int>&piles,int h){
            int n = piles.size();
            int count = 0;
            for(int i=0; i<n; i++){
                if(count > h) return false;
                 if(mid>=piles[i]) count++;
                 else if(piles[i]%mid == 0) count = count + piles[i]/mid;
                 else count = count + (piles[i]/mid + 1);
            } 
            if(count > h) return false;
            else return true;
        }
    
        int minEatingSpeed(vector<int>& piles, int h) {
            int n = piles.size();
            int max = INT_MIN;
            for(int i =0; i<n; i++){
                if(max<piles[i]) max = piles[i];
                
            }
            if(n == h) return max;
            int low = 1;
            int high = max;
            int minSpeed = max;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(check(mid,piles,h)){
                    minSpeed = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            return minSpeed;
        }
    };
    
int main(){
    return 0;
}