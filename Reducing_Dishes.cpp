#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int maxSatisfaction(vector<int>& satisfaction) {
            int n = satisfaction.size();
            sort(satisfaction.begin(),satisfaction.end());
            vector<int> suf(n);
            int sum = 0;
            for(int i = n-1; i>=0; i--){
                 sum = sum + satisfaction[i];
                 suf[i] = sum;
            }
            int idx = -1;
            for(int i = 0; i<n; i++){
                if(suf[i]>0) {
                    idx = i;
                    break;
                }
            } 
            int maxSat = 0;
            if(idx != -1){
            for(int i = 1; idx<n; i++){
                maxSat = maxSat + i*satisfaction[idx];
                idx++;
            }
            return maxSat;
            }
            return 0;
        }
    };

int main(){
    return 0;
}