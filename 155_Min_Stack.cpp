#include<iostream>
#include<stack>
#include<climits>
using namespace std;

class MinStack {
    public:
        stack<long  long> st;
        // stack<int> helper;
        long long min;
        MinStack() {
           min = LLONG_MAX; 
        }
        // Method -1 
        
        // void push(int val) {
        //     st.push(val);
        //     if(helper.size() == 0 || val < helper.top()) helper.push(val);
        //     else helper.push(helper.top());
        // }
        
        // void pop() {
        //     st.pop();
        //     helper.pop();
        // }
        
        // int top() {
        //     return st.top();
        // }
        
        // int getMin() {  //O(1)
        //     return helper.top();
        // }
    
        //Method - 2   - Use to make space complexity O(1).
    
        void push(int val) {
            long long x = (long long)val;
             if(st.size() == 0){
                st.push(x);
                min = x;
             } 
             else if(x >= min) st.push(x);
             else{
                st.push(2*x - min);  // A fake value is pushed into the stack.
                min = x;
             }
    
        }
    
        void pop() {
             if(st.top() < min){ //st.top < min : A fake value is present.
                //Retrieve the old min 
                long long oldMin = 2*min - st.top();
                min = oldMin;
             
             }
                st.pop();
        }
    
        int top() {
            if(st.top() < min) return (int)min;
            else return (int)st.top();
        }
    
        int getMin() {
             return (int)min;  
        }
};
    