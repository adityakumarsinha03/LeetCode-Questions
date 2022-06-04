/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0){
            return head;
        }
        ListNode* fast= head, *slow= head, *temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        k= k%count;
        int i=1;
        while(i<=k && fast!=NULL){
            fast=fast->next;
            i++;
        }
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        
        return head;
    }
};