#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            int n = nums2.size();
            stack<int> st;
            unordered_map<int,int> umap;
            umap[nums2[n-1]] = -1;
            st.push(nums2[n-1]);
            for(int i = n-2; i>=0; i--){
                while(st.size() >0 && st.top() <= nums2[i]) st.pop();
                if(st.size() == 0) umap[nums2[i]]  = -1;
                else umap[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
            vector<int> ans;
            for(auto it : nums1){
                ans.push_back(umap[it]);
            }
            return ans;
        }
};