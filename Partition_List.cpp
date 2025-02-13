#include <iostream>
#include <list>
#include <vector>
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
        ListNode* partition(ListNode* head, int x) {
            ListNode* low = new ListNode(0);
            ListNode* high = new ListNode(0);
            ListNode* th = high;  //temp ka high
            ListNode* tl = low;   // temp ka low
            ListNode* temp = head;
    
            while(temp!=NULL){
                 if(temp->val <x){
                    tl->next = temp;
                    temp = temp->next;
                    tl = tl->next;
                    tl->next = NULL;
                 }
                 else{
                    th->next = temp;
                    temp = temp->next;
                    th = th->next;
                    th->next = NULL;
                 }
            }
            tl->next = high->next;
            return low->next;
        }
};

int main()
{
    return 0;
}