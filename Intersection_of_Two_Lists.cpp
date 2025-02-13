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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* tempA = headA;
            ListNode* tempB = headB;
            int lenA=0,lenB=0;
            while(tempA != NULL){
                lenA++;
                tempA = tempA->next;
            }
            while(tempB != NULL){
                lenB++;
                tempB = tempB->next;
            }
            tempA = headA;
            tempB = headB;
            if(lenA > lenB){
              int diff = lenA - lenB;
              for(int i =1; i<= diff; i++){
                tempA = tempA->next;
              }
              while(tempA != tempB){
                tempA = tempA->next;
                tempB = tempB->next;
              }
              return tempA;
            }
            else{
                int diff = lenB - lenA;
              for(int i =1; i<= diff; i++){
                tempB = tempB->next;
              }
              while(tempA != tempB){
                tempA = tempA->next;
                tempB = tempB->next;
              }
              return tempA;
            }
            return NULL;
        }
    };

int main(){
    return 0;
}