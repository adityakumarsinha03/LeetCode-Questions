/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>um;
        Node* temp=head;
        while(temp!=NULL){
            Node* newnode= new Node(temp->val);
            um[temp]=newnode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
           um[temp]->next= um[temp->next];
           um[temp]->random= um[temp->random]; 
           temp=temp->next; 
        }
        return um[head];
    }
};