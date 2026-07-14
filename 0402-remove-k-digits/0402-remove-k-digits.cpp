class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        int n = num.length();
        for(int i = 0; i < n; i++) {
            while(result.length() > 0 && result.back() > num[i] && k > 0) {
                result.pop_back();
                k--;
            }
            if(result.length() > 0 || num[i] != '0')
                result.push_back(num[i]); //remove starting zeroes.
        }
        while(result.length() > 0 && k > 0) {
            result.pop_back();
            k--;
        }
        return result == "" ? "0" : result;
    }
};