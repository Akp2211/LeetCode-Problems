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
    Node *child;
    Node *prev;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x,  Node *next) : val(x), next(next) {}
};

class Solution {
    public:
        Node* flatten(Node* head) {
            Node* temp = head;
            Node* a = NULL;
            Node* c = NULL;
            while(temp){
                a = temp->next;
                if(temp->child != NULL){
                    
                    c = temp->child;
                    c = flatten(c);
                    temp->child = NULL;
                    a = temp->next;
                    temp->next = c;
                    c->prev = temp;
                    while(c->next){
                        c = c->next;
                    }
                    c->next = a;   //Here a might become NULL
                    if(a != NULL) a->prev = c;
                }
                temp = a;
            }
            return head;
        }
};

int main()
{
    return 0;
}