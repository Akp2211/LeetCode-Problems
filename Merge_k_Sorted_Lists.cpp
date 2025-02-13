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
        ListNode* merge(ListNode* list1, ListNode* list2) {
           ListNode* c = new ListNode(100);
           ListNode* temp= c;
           while(list1!= NULL && list2 != NULL){
            if(list1->val<= list2->val){
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
           } 
           if(list1== NULL) temp->next = list2;
           else temp->next = list1;
           return c->next;
        }
    
        ListNode* mergeKLists(vector<ListNode*>& v) {
            if(v.size() == 0) return NULL;
            while(v.size()>1){
                ListNode* a = v[0];
                v.erase(v.begin());
                ListNode* b = v[0];
                v.erase(v.begin());
                ListNode* c = merge(a,b);
                v.push_back(c);
            }
            return v[0];
        }
};

int main(){
    return 0;
}