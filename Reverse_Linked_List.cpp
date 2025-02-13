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
};

int main()
{
    return 0;
}