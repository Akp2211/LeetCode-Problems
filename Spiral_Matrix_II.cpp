#include<iostream>
#include<list>
#include<vector>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> arr(n,vector<int>(n,0));
            int minr = 0;
            int maxr = n-1;
            int minc = 0;
            int maxc = n-1;
            int count = 1;
            while(minr<=maxr && minc<=maxc){
                //right
                for(int j = minc; j<=maxc; j++){
                    arr[minr][j] = count++;
                }
                minr++;
                if(minr>maxr || minc>maxc) break;
                //down
                for(int i = minr; i<=maxr; i++){
                    arr[i][maxc] = count++;
                }
                maxc--;
                if(minr>maxr || minc>maxc) break;
                //left
                for(int j = maxc; j>=minc; j--){
                    arr[maxr][j] = count++;
                }
                maxr--;
                if(minr>maxr || minc>maxc) break;
                //up
                for(int i = maxr; i>=minr; i--){
                    arr[i][minc] = count++;
                }
                minc++;
                if(minr>maxr || minc>maxc) break;
            }
            return arr;
        }
};

int main(){
    return 0;
}