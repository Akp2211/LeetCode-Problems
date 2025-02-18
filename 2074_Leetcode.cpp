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
            ListNode* temp = head;
            ListNode* Left = NULL;
            ListNode* Right = NULL;
            ListNode* lPrev = NULL; // Left ka previous
            ListNode* rNext = NULL; //Right ka next
            int n=1;
            while(temp){
              if(n == left-1) lPrev = temp;
              if(n == left) Left = temp;
              if(n == right) Right = temp;
              if(n == right+1) rNext = temp;
              temp = temp->next;
              n++;
            }
            if(lPrev) lPrev->next = NULL;
            if(Right) Right->next = NULL;
            Right = reverseList(Left);
            if(lPrev) lPrev->next = Right;
            Left->next = rNext;
            if(lPrev) return head;
            return Right;
        }
    
        ListNode* reverseEvenLengthGroups(ListNode* head) {
            ListNode* temp = head;
            int gap = 1;
            while(temp && temp->next){
                int remLen = 0;
                ListNode* t = temp->next;
                for(int i = 1; i<=gap+1 && t!= NULL; i++){
                    t = t->next;
                    remLen++;
                }
                if(remLen < gap+1) gap = remLen + 1;
                if(gap%2 != 0) reverseBetween(temp,2,2+gap);
                gap++;
                for(int i =1; i<= gap && temp; i++){
                    temp = temp->next;
                }
            }
            return head;
        }
};

int main()
{
    return 0;
}