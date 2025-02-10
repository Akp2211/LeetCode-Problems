#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
class Solution {
    public:
        string multiply(string num1, string num2) {
             if (num1 == "0" || num2 == "0")
            return "0";
    
        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0);
    
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
    
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int digit_mul = (num1[i] - '0') * (num2[j] - '0');
                result[i + j] += digit_mul;
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
    
        while (result.size() > 1 && result.back() == 0)
            result.pop_back();
    
        reverse(result.begin(), result.end());
    
        string resultStr;
        for (int num : result)
            resultStr += to_string(num);
    
        return resultStr;
        }
    };

int main(){
    return 0;
}    