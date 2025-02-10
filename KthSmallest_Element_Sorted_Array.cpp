#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            // int m = matrix.size();
            // int n = matrix[0].size();
            // vector<int> v;
            
            // for (int i =0; i<m; i++){  // O(n^2)
            //     for(int j =0; j<n; j++){
            //        v.push_back(matrix[i][j]);
            //     }
            // }
            // sort(v.begin(),v.end());
    
            // return v[k-1];
    
            //Method - 2
            int m = matrix.size();
            int n = matrix[0].size();
            priority_queue<int> pq;
            for (int i =0; i<m; i++){
                for(int j =0; j<n; j++){
                   pq.push(matrix[i][j]);
                   if(pq.size()> k) pq.pop();
                }
            }
            return pq.top();
        }
    };
    
int main(){
    return 0;
}    