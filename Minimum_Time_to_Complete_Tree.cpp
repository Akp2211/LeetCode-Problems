#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
    public:
        bool check(long long mid,vector<int>& time, int totalTrips){
             long long trip = 0;
             int n = time.size();
            for(int i =0; i<n; i++){
                trip = trip + mid/(long long)time[i];
            }
            if(trip<(long long)totalTrips) return false;
            else return true;
        }
    
        long long minimumTime(vector<int>& time, int totalTrips) {
            int n = time.size();
            int mx = -1;
            for(int i =0; i<n; i++){
                mx = max(mx,time[i]);
            }
            long long low = 1;
            long long high = (long long)mx*(long long)totalTrips;
            long long ans = -1;
            while(low<=high){
                long long mid = low + (high - low)/2;
                if(check(mid,time,totalTrips)){
                    ans = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            return ans;
        }
    };

int main(){
    return 0;
}