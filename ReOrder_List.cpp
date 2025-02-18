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
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* Next;
            while(curr != NULL){
                Next = curr->next;
                curr->next = prev;;
                prev = curr;
                curr = Next;
            }
            return prev;
        }
    
        void reorderList(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast->next !=NULL && fast->next->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* newHead = reverseList(slow->next);
            slow->next = NULL;
            ListNode* Head = new ListNode(0);
            ListNode* temp = Head;
            int i =1;
            while(head){
                if(i%2 != 0){
                   temp->next = head;
                   head = head->next;
                }  
                else{
                    temp->next = newHead;
                    newHead = newHead->next;
                }
                i++;
                temp = temp->next;
            }
            if(newHead != NULL)  temp->next = newHead;
            
        }
    };

int main()
{
    return 0;
}