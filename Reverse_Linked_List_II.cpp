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
    
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if(left == right) return head;
            if(head == NULL || head->next == NULL) return head;
            ListNode* Left = head;
            ListNode* Right = head;
            ListNode* lPrev = head; // Left ka previous
            ListNode* rNext = head; //Right ka next
            int i =1;
            int j = 1;
            while(i != left){
                Left = Left->next;
                i++;
            }
            i = 1;
            while(i < left-1){
                lPrev = lPrev->next;
                i++;
            }
            while(j != right){
                Right = Right->next;
                j++;
            }
            rNext = Right->next;
            if(left == 1){
             Right->next = NULL;
             Left = reverseList(Left);
             Right = Left;
             while(Right->next != NULL){
                Right = Right->next;
             }
             Right->next = rNext;
             return Left;
            }
            
            lPrev->next = NULL;
            Right->next = NULL;
            Left = reverseList(Left);
            Right = Left;
            while(Right->next != NULL){
                Right = Right->next;
            }
            lPrev->next = Left;
            Right->next = rNext;
            return head;
        }
};

int main()
{
    return 0;
}