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
    // Iterative
    ListNode* reverseList(ListNode* head) {
        ListNode *prev= NULL, *curr= head, *next= NULL;
        while(curr!=NULL){
            next= curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }    
    
    /* // Recursive
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* smallAns= reverseList(head->next);
        head->next->next= head;
        head->next=NULL;
        return smallAns;
    }  */
};