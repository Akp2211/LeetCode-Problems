#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
    public:
        vector<int> deckRevealedIncreasing(vector<int>& deck) {
            sort(deck.begin(),deck.end());
            int n = deck.size();
            vector<int> ans(n);
            queue<int> q;
            for(int i =0; i<n; i++){
                q.push(i);
            }
            int i =0;
            while(q.size() !=0){
                int idx = q.front();
                q.pop();
                q.push(q.front());
                q.pop();
                ans[idx] = deck[i++];
            }
            return ans;
        }
};