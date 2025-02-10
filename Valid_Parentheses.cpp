#include<iostream>
#include<string>
#include<stack>

using namespace std;
class Solution {

    public:
    
     bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> open, close;
    
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')  open.push(s[i]);
            if (!open.empty() && ((s[i] == ')' && open.top() == '(') || (s[i] == '}' && open.top() == '{' ||   
                      (s[i]== ']' && open.top() == '['))))
                          close.push(s[i]), open.pop();
    
     }
     if (close.size() * 2 == s.size()) return true;
    
     return false;
    
     }
    };

int main(){
    return 0;
}