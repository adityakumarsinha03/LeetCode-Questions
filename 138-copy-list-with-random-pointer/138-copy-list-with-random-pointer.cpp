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
    // O(n)||O(1)
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* iter= head;
        //step 1
        while(iter!=NULL){
            Node* newnode= new Node(iter->val);
            newnode->next=iter->next;
            iter->next=newnode;
            iter=iter->next->next;
        }
        //step 2
        iter= head;
        while(iter!=NULL){
            if(iter->random != NULL){
              iter->next->random= iter->random->next;
            }    
            iter=iter->next->next;  
        }
        //step 3
        Node* copyhead= head->next;
        Node* dummy= copyhead, *front= head;
        iter= head;
        while(iter!=NULL){
            front= iter->next->next;
            iter->next=front;
            if(front){
             dummy->next=front->next;
            }    
            
            iter=front;
            dummy=dummy->next;
        }
        return copyhead;
    }
    
    /*  //  O(n)||O(n)
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
    } */
};