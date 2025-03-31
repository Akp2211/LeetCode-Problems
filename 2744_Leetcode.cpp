#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    public:
        int maximumNumberOfStringPairs(vector<string>& words) {
            int count = 0;
            //Method -1
    
            // for(int i=0; i<words.size()-1; i++){
            //     string rev = words[i];
            //     reverse(rev.begin(),rev.end());
            //     for(int j=i+1; j<words.size(); j++){
            //         if(rev == words[j]) count++;
            //     }
            // }
    
            //Method -2
            unordered_set<string> s;
            for(int i=0; i<words.size(); i++){
                string rev = words[i];
                reverse(rev.begin(),rev.end());
                if(words[i] == rev) continue;
                if(s.find(rev) != s.end()) count++;
                else s.insert(words[i]);
            }
    
            return count;
        }
};