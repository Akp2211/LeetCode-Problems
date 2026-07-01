class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;
        for(int ele : nums)
            ans.push_back(ele);
        return ans;
    }
};