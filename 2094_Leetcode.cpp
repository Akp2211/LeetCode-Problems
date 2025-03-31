#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& arr) {
            vector<int> ans;
            unordered_map<int,int> m;
            for(int ele : arr){
                m[ele]++;
            }
            for(int i =100; i<1000; i+=2){
                int x = i;
                int a = x%10;  //Ones place digit
                if((m.find(a) == m.end()))  continue; //Nahi h toh skip karo
                x = x/10;
                m[a]--;
                if(m[a] == 0) m.erase(a);
                int b = x%10;   //tens place digit
                if(m.find(b) == m.end()){     //Nahi h toh skip karo
                    m[a]++;
                    continue;
                }
                x = x/10;
                m[b]--;
                if(m[b] == 0) m.erase(b);
                int c = x%10;   //hundreds place digit
                if(m.find(c) == m.end()){      //Nahi h toh skip karo
                    m[a]++;
                    m[b]++; 
                    continue;
                }
                x = x/10;
                m[c]--;
                if(m[c] == 0) m.erase(c);
                ans.push_back(i);
                m[a]++;
                m[b]++;
                m[c]++;
                
            }
            return ans;
        }
};