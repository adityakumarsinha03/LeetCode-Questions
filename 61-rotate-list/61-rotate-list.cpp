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
        ListNode* curr= head;
        //edge cases
        if(head==NULL || k==0){
            return head;
        }
        // length
        int count=1;
        while(curr->next!=NULL){
            curr=curr->next;
            count++;
        }
        
        curr->next=head;
       
        k= k%count;
        int i= count-k;
        while(i--){
            curr= curr->next;
        }
        
        head= curr->next;
        curr->next= NULL;
        
        return head;
    }
};