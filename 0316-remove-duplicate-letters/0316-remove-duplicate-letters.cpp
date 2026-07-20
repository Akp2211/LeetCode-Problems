class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        vector<bool> taken(26, false); //O(1) space
        vector<int> lastIndex(26); //O(1) space
        for(int i = 0; i < s.size(); i++) {
            lastIndex[s[i]-'a'] = i;
        }
        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if(taken[idx] == true) continue;
            while(result.length() > 0 && s[i] < result.back() && lastIndex[result.back() - 'a'] > i) {
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(s[i]);
            taken[idx] = true;
        }
        return result;
    }
};