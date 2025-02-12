#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
    public:
       int highest_divisor(int n){
            for(int i =2; i<=sqrt(n); i++){
                if(n%i == 0) {
                    return n/i;
                } 
            }
            return 1;
       }
        bool isPrime(int n){
            if(n<=1) return false;
            for(int i =2; i<=sqrt(n); i++){
                if(n%i == 0) return false;
    
            }
            return true;
        }
    
        int minSteps(int n) {
            if(n==1) return 0;
            if(isPrime(n)) return n;
            int count = 0;
           
            while(n>1){
                int hf = highest_divisor(n);
                count += n/hf;
                 n = hf;
            }
            return count;
        }
    };

int main(){
    return 0;
}