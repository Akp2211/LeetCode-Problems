#include<vector>
#include<stack>
using namespace std;

class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            vector<int> a(2 * n);
            for (int i = 0; i < 2 * n; i++) {
                a[i] = nums[i % n];
            }
            stack<int> s;
            vector<int> ans(2 * n);
    
            for (int i = 2 * n - 1; i >= 0; i--) {
                while (s.size() && s.top() <= a[i]) {
                s.pop();
                }
    
                if (s.size() && s.top() > a[i]) {
                    ans[i] = s.top();
                }
                else {
                    ans[i] = -1;
                }
    
                s.push(a[i]);
            }
    
            for (int i = 0; i < n; i++) {
                nums[i] = ans[i];
            }
    
            return nums;
        }
};