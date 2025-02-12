#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
    public:
        bool checkPerfectNumber(int num) {
            int sum = 0;
            for(int i = 1; i<sqrt(num); i++){
               if(num%i == 0) sum += i;
            }
            for(int i = sqrt(num); i>=2; i--){
                if(num%i == 0) sum += num/i;
            }
            return (sum == num);
        }
    };

int main(){
    return 0;
}