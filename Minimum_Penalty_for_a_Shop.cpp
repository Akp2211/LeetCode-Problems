#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int bestClosingTime(string customers) {
            int n = customers.length();
            int p = 0;
            vector<int> pre(n+1);
            pre[0] = 0;
            for(int i =0; i<n; i++){
                if(customers[i] == 'N') p++;
                 pre[i+1] = p;
            }
            p = 0;
            vector<int> post(n+1);
            post[n] = 0;
            for(int i = n-1; i>=0; i--){
                if(customers[i] == 'Y') p++;
                 post[i] = p;
            }
            int minPen = n;
            for(int i =0; i<=n; i++){
                pre[i] = pre[i] + post[i];
                int pen = pre[i];
                minPen = min(minPen,pen);
            }
            for(int i =0; i<=n; i++){
                if(minPen == pre[i]) return i;
            }
            return 0;
        }
    };

int main(){
    return 0;
}