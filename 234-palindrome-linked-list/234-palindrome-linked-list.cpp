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
    ListNode* reverseLL(ListNode* head){        
        ListNode* prev= NULL, *next= NULL, *curr= head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
         if(head==NULL || head->next== NULL)
            return head;
        ListNode *slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* firstHead= head;
        ListNode* secondHead= slow->next;
        slow->next= NULL;
        secondHead= reverseLL(secondHead);
        
        ListNode* secondLL= secondHead;
        bool ans= true;
        while(secondHead!=NULL ){
            if(firstHead->val != secondHead->val){
                ans= false;
                break;
            }
            secondHead=secondHead->next;
            firstHead=firstHead->next;
        }
        
        secondHead= reverseLL(secondLL);
        slow->next= secondHead;
        return ans;
    }
};