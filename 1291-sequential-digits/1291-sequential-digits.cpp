class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        for(int i=1; i<9; i++) q.push(i);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            if(temp>=low && temp<=high) ans.push_back(temp);
            int lastDig = temp%10;
            if(lastDig<9){
                q.push(temp*10+(lastDig+1));
            } 
        }
        return ans;
    }
};