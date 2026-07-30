class Solution {
public:
    void solve(vector<int>& nums, int start, int target,vector<int>& comb, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue; // Skip duplicates
            if (nums[i] > target) break;
            comb.push_back(nums[i]);
            solve(nums, i + 1, target - nums[i], comb, ans);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> comb;
        solve(nums, 0, target, comb, ans);
        return ans;
    }
};