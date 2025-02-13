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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            int len = 0;
            ListNode* temp = head;
            while(temp!=NULL){
                len++;
                temp = temp->next;
            }
            temp = head;
            if(len == n){
                head = head->next;
                return head; 
            }
            //Nth from beginning.
            n = len - n +1;
            for(int i =1; i<n-1; i++){
                temp = temp->next;      //temp reaches before a node which is to be remove.
            }
            temp->next = temp->next->next;
            return head;
        }
};

int main(){
    return 0;
}