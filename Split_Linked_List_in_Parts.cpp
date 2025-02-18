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
        vector<ListNode*> splitListToParts(ListNode* head, int k) {
            vector<ListNode*> v;
            if(k == 1){
                v.push_back(head);
                return v;
            }
            if(head == NULL){
                int a = 1;
                while(a<=k){
                    v.push_back(head);
                    a++;
                }
                return v;
            }
            int n = 1;
            ListNode* temp = head;
            while(temp->next){
                temp = temp->next;
                n++;
            }
            int rem = n% k;
            int len = n/k;
            ListNode* t = head;
            int i = 1;
            while(i<=k){
                while(rem > 0){
                temp = head;
                for(int j = 1; j< len+1; j++){
                    temp = temp->next;
                }
                t = temp->next;
                temp->next = NULL;
                v.push_back(head);
                head = t;
                rem--;
                i++;
               } 
               temp = head;
               if(temp == NULL){
                  v.push_back(head);
                  i++;
               }
               else{
               for(int j =1; j<len; j++){
                temp = temp->next;
               }
               t = temp->next;
               temp->next = NULL;
               v.push_back(head);
               head = t;
               i++;
            }
            }
           return v;
        }
};

int main()
{
    return 0;
}