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
    ListNode *random;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x,   ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        head = temp2; // Reintialize head.
        ListNode* prev = NULL;
        while(temp1 != NULL && temp2 != NULL){
            //Swap
            temp1->next = temp2->next;
            temp2->next = temp1;
            if(prev) prev->next = temp2;
            
            //Move forward. 
            prev = temp1;
            temp1 = temp1->next;
            if(temp1 != NULL) temp2 = temp1->next;
        }
        return head;
    }
};