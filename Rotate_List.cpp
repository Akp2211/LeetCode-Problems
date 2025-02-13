#include<iostream>
#include<list>
#include<vector>
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
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == NULL) return head;
            int n = 1;
            ListNode* temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
                n++;
            }
            ListNode* tail = temp;
            temp = head;
            k = k%n;
            cout<<k;
            if(k==0) return head;
            for(int i =1; i<n-k; i++){
                temp = temp->next;
            }
            cout<<"  "<<temp->val;
            tail->next = head;
            head = temp->next;
            temp->next = NULL;
            
           return head;
        }
};

int main(){
    return 0;
}