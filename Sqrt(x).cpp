#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int mySqrt(int x) {
            int low = 0;
            int high = x;
            while(low<=high){
                int mid = low + (high-low)/2;
                long long m = (long long)mid;
                long long y = (long long)x;
                if(y == m*m) return mid;
                if(y>m*m)  low = mid + 1;
                if(y<m*m)  high = mid - 1;
            }
            return high;
        }
    };
    
int main(){
    return 0;
}    