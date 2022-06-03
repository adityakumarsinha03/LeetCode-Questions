/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* slow= head, *fast= head, *entry= head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(slow!=entry){
                    slow=slow->next;
                    entry=entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }    
    /*   // Hashing  //O(n) || O(n)
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp= head;
        unordered_set<ListNode*> s;
        while(temp){
            if(s.find(temp)==s.end()){
                s.insert(temp);
                temp=temp->next;
            }else{
                return temp;
            }
        }
        return NULL;
    }  */
};