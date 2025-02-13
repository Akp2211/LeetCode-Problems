#include<iostream>
#include<list>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode* slow = head;
            ListNode* fast = head;
            bool flag = false;
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast) {
                    flag = true;
                    break;
                }
            }
            if(flag == true){
                ListNode* temp = head;
                while(temp != slow){
                    temp = temp->next;
                    slow = slow->next;
                }
                return slow;
            }
            return NULL;
        }
    };

int main(){
    return 0;
}