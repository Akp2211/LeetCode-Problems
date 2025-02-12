#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
            int k = minutes;
            vector<int>& arr = customers;
            int n = arr.size();
            int prevLoss = 0;
            for(int i=0; i<k; i++){
                if(grumpy[i] == 1) prevLoss += arr[i];
            } 
            int maxLoss = prevLoss;
            int maxIdx = 0;
            int i =1;
            int j = k;
            while(j<n){
               int curLoss = prevLoss;
               if(grumpy[j] == 1) curLoss += arr[j];
               if(grumpy[i-1] == 1) curLoss -= arr[i-1];
               if(maxLoss<curLoss){
                maxLoss = curLoss;
                maxIdx = i;
               }
               prevLoss = curLoss;
               i++;
               j++;
            }
            //Filing Zero's in grumpy array window
            for(int i = maxIdx; i<(maxIdx+k); i++){
                grumpy[i] = 0;
            }
            //sum of satisfaction.
            int sum = 0;
            for(int i = 0; i<n; i++){
                if(grumpy[i] == 0) sum += arr[i]; 
            }
            return sum;
    
        }
    };

int main(){
    return 0;
}