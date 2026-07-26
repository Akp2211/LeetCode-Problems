class Solution {
public:
    int maxProduct(int n) {
        int prod = 0;
        while(n>0){
            int dig1 = n%10;
            n /= 10;
            int j = n;
            while(j>0){
                int dig2 = j%10;
                j=j/10;
                prod = max(prod,dig1*dig2);
            }
        }
        return prod;
    }
};