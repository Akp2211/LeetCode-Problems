#include <iostream>
#include <list>
#include <vector>
#include<climits>
using namespace std;
//  Definition for singly-linked list.
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
        vector<int> nodesBetweenCriticalPoints(ListNode* head) {
             vector<int> ans(2,-1);
             int idx = 1;
             int fidx = -1;
             int f = -1;
             int s = -1;
             int sidx = -1;
             ListNode* a = head;
             ListNode* b = head->next;
             ListNode* c = b->next;
             int mind = INT_MAX;
             if(c == NULL) return ans;
             while(c){
                  if((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)){
                       //Max distance
                       if(fidx == -1) fidx = idx;
                       else sidx = idx;
                        //Min Distance
                        f = s;
                       s = idx;
                       if(f != -1){
                        int d = s - f;
                        mind = min(mind,d);
                       }
                  } 
                  a = a->next;
                  b= b->next;
                  c = c->next;
                  idx++;
             }
             if(fidx != -1 && sidx != -1) ans[1] = sidx - fidx;
             if(mind != INT_MAX) ans[0] = mind;
             return ans;
        }
};

int main()
{
    return 0;
}