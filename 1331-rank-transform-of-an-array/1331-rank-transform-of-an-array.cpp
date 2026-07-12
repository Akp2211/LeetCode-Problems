class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> v;
        v=arr;
        sort(v.begin(),v.end());
        vector<int> ans(n);
        unordered_map<int,int> mp;
        int rank=1;
        for(int ele : v){
            if(mp.find(ele) == mp.end()) {
                mp[ele] = rank;
                rank++;
            }
        }
        for(int i=0; i<n; i++){
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};