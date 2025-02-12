#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
    public:
        typedef pair<int,int> pi;
        vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            vector<int> v(k);   // K element ko push karna h
            //Method - 1
    
            // int n = arr.size();
            // if(arr[0]>x){
            //     for(int i = 0; i<k; i++){
            //         v[i] = arr[i];
            //     }
            //     return v;
            // }
            // if(arr[n-1]<x){
            //     int i = n-1;
            //      int j = k-1;
            //    while(j>=0){
            //     v[j] = arr[i];
            //     j--;
            //     i--;
            //    }
            //     return v;
            // }
            // int low = 0;
            // int high = n-1;
            // int t = 0;
            // bool flag = false;      //Check x is present in arr or not
            // int mid = -1;    
            // // Binary Search   
            // while(low<=high){
            //     mid = low + (high - low)/2;
            //     if(arr[mid] == x){
            //         flag = true;
            //         v[t] = arr[mid];
            //         t++;
            //         break;
            //     }  
            //     else if(arr[mid] > x) high = mid - 1;
            //     else low = mid + 1;
            // }
            // int lb = high;
            // int ub = low;
            // if(flag == true){
            //     lb = mid - 1;
            //     ub = mid + 1;
            // }
            // while(t<k && lb>=0 && ub < n){
            //     int d1 = abs(x - arr[lb]);
            //     int d2 = abs(x - arr[ub]);
            //     if(d1<=d2){
            //         v[t] = arr[lb];
            //         t++;
            //         lb--;
            //     }
            //     else{
            //         v[t] = arr[ub];
            //         t++;
            //         ub++;
            //     }
            // }
            // if(lb<0){
            //    while(t<k){
            //     v[t] = arr[ub];
            //      t++;
            //      ub++;
            //    }
            // }
            // if(ub>n-1){
            //     while(t<k){
            //         v[t] = arr[lb];
            //         t++;
            //         lb--;
            //     }
            // }
            // sort(v.begin(),v.end());
            // return v;
    
            //Method -2
            priority_queue<pi> pq; //Max Heap
            for(int i =0; i<arr.size(); i++){
                int d = abs(x - arr[i]);
                cout<<d<<" ";
                pq.push({d,arr[i]});
                if(pq.size() > k) pq.pop();
            }
            int i =0;
            while(pq.size() > 0){
                v[i] = pq.top().second;
                pq.pop();
                i++;
            }
            sort(v.begin(),v.end());
            return v;
        }
    };
    
int main(){
    return 0;
}