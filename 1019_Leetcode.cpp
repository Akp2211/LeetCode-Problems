#include<stack>
#include<vector>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        vector<int> nextLargerNodes(ListNode* head) {
            stack<int> st;
            vector<int> arr;
            while(head){
                arr.push_back(head->val);
                head = head->next;
            }
            int n = arr.size();
            vector<int> ans(n);
            ans[n-1] = 0;
            st.push(arr[n-1]);
            for(int i = n-2; i>=0; i--){
                while(st.size()>0 && st.top()<= arr[i]) st.pop();
                if(st.size() != 0) ans[i] = st.top();
                st.push(arr[i]);
            }
    
    
            return ans;
        }
};