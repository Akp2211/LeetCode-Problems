#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    public:
        bool check(int mid,vector<int>& w,int d){
            int n = w.size();
            int count = 0;
            int m = mid;
            for(int i=0; i<n; i++){
                if(m>=w[i]){
                    m -= w[i];
                }
                else{
                    count++;
                    m = mid;
                    m -= w[i];
                }
            } 
            cout<<count<<" ";
            if(count >= d) return false;
            else return true;
        }
    
        int shipWithinDays(vector<int>& weights, int days) {
            int n = weights.size();
            int sum = 0;
            int max = INT_MIN;
            for(int i =0; i<n; i++){
                if(max<weights[i]) max = weights[i];
                sum = sum +weights[i];
            }
          int low = max;
          int high = sum;
          int minCapacity = sum;
          while(low<=high){
            int mid = low + (high - low)/2;
            // cout<<mid<<" ";
            if(check(mid,weights,days)){
                minCapacity = mid;
                high = mid - 1;
            }
            else low = mid + 1;
          }
          return minCapacity;
        }
    };

int main(){
    return 0;
}