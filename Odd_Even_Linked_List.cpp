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
        ListNode* oddEvenList(ListNode* head) {
             ListNode* even = new ListNode(0);
            ListNode* odd = new ListNode(0);
            ListNode* tO = odd;  //odd ka temp
            ListNode* tE = even;   //even ka temp
            ListNode* temp = head;
            int count = 1;
            while(temp != NULL){
                if(count % 2 == 0){
                    tE->next = temp;
                    temp = temp->next;
                    tE = tE->next; 
                }
                else{
                    tO->next = temp;
                    temp = temp->next;
                    tO = tO->next; 
                }
                count++;
            }
            tO->next = even->next;
            tE->next = NULL;
            return odd->next;
        }
};

int main()
{
    return 0;
}