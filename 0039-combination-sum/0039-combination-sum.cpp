class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int>& nums,int idx,int target,vector<vector<int>> &ans,vector<int>& comb){
        if(target<0 || idx == nums.size()) return;
        if(target==0) {
            if(s.find(comb) == s.end()){
                ans.push_back({comb});
                s.insert(comb);
            }
            return;
        }
        comb.push_back(nums[idx]);
        solve(nums,idx+1,target-nums[idx],ans,comb); //single entry;
        solve(nums,idx,target-nums[idx],ans,comb); //multiple entry;
        comb.pop_back();
        solve(nums,idx+1,target,ans,comb); //leave
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        solve(nums,0,target,ans,comb);
        return ans;
    }
};