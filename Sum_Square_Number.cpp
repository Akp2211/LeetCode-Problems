#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
    public:
        bool isperfectSquare(int n){
             int a = sqrt(n);
             if(a*a == n) return true;
             else return false;
        }
    
        bool judgeSquareSum(int c) {
            int x = 0;
            int y = c;
    
            while(x<=y){
                if(isperfectSquare(x) && isperfectSquare(y)) return true;
               else if(!isperfectSquare(y)){
                y = int(sqrt(y)) * int(sqrt(y));
                x = c-y;
               }
               else{
                x = (int(sqrt(x))+1) * (int(sqrt(x))+1);
                y = c-x;
               }
            }
            return false;
        }
    };

int main(){
    return 0;
}