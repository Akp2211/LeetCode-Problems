#include <iostream>
#include <list>
#include <vector>
#include<climits>
using namespace std;
//  Definition for singly-linked list.
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x,  Node *next) : val(x), next(next) {}
};

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            //Create Deep copy without assigning random pointer
            Node* dummy = new Node(0);
            Node* t = dummy;
            Node* temp = head;
            if(temp == NULL) return NULL;
            while(temp){
                Node* a = new Node(temp->val);
                t->next = a;
                temp = temp->next;
                t = t->next; 
            }
            // Alternate Connections b/w Original and duplicate LL (merge)
            Node* duplicate = dummy->next;
            Node* a = head;
            Node* b = duplicate;
            dummy = new Node(-1);
            Node* tempD = dummy;
            while(a){
                tempD->next = a;
                a = a->next;
                tempD = tempD->next;
                tempD->next = b;
                b = b->next;
                tempD = tempD->next;
            }
            dummy = dummy->next;
            //Assigning random pointer of duplicate
            Node* t1 = dummy;  //Traverse in original List
            Node* t2 = dummy->next;  // Traverse in duplicate List
            while(t1){
               t2 = t1->next;
               if(t1->random != NULL) t2->random = t1->random->next;
               t1 = t1->next->next; 
            }
            //Seperate the original and dupiicate List.
            Node* d1 = new Node(-1);
            Node* d2 = new Node(-1);
            t1 = d1;
            t2 = d2;
            t = dummy;
            while(t){
                t1->next = t;
                t = t->next;
                t1 = t1->next;
    
                t2->next = t;
                t = t->next;
                t2 = t2->next;
            }
            t1->next = NULL;
            t2->next = NULL;
            d1 = d1->next;  //original
            d2 = d2->next;  //duplicate
            return d2;
        }
    };

int main()
{
    return 0;
}