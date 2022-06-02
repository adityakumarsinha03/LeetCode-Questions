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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ll1 = l1;
        ListNode* ll2 = l2;
        int carry= 0, sum= 0;
        ListNode* dummy = new ListNode(0);    
        ListNode* prev = dummy;
        while(ll1 && ll2){     //ll1 != NULL && ll2 != NULL
            sum= carry+ ll1->val + ll2->val;
            ListNode* newnode = new ListNode(sum%10);
            carry= sum/10;
            prev->next= newnode;
            prev=newnode;
            ll1= ll1->next;
            ll2= ll2->next;
        }
        while(ll1){
            sum= carry+ ll1->val;
            ListNode* newnode = new ListNode(sum%10);
            carry= sum/10;
            prev->next= newnode;
            prev=newnode;
            ll1= ll1->next;
        }
        while(ll2){
            sum= carry+ ll2->val;
            ListNode* newnode = new ListNode(sum%10);
            carry= sum/10;
            prev->next= newnode;
            prev=newnode;
            ll2= ll2->next;
        }
        if(carry){
            ListNode* newnode = new ListNode(carry);
            prev->next= newnode;
        }
        return dummy->next;
    }
};