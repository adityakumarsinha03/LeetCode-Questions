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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
       ListNode* fh= NULL, *ft= NULL;    //fh: final head
       if(list1->val <= list2->val){
           fh=list1;
           ft=list1;
           list1=list1->next;
       }else{
           fh=list2;
           ft=list2;
           list2=list2->next;
       } 
       
        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){
                ft->next= list1;
                ft=list1;
                list1= list1->next;
            }else{
                ft->next= list2;
                ft=list2;
                list2= list2->next;
            }
        }
        
        if(list1!=NULL){
            ft->next=list1;
        }if(list2!=NULL){
            ft->next=list2;
        }
        
        return fh;
    }    
    
    
    /*   //STRIVER  
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        
        if(list1->val > list2->val){
            swap(list1, list2);
        }
        ListNode* res= list1;
        while(list1!=NULL && list2!=NULL){
            ListNode* temp=NULL;
            while(list1!=NULL && list1->val <= list2->val){
                temp=list1;
                list1=list1->next;
            }
            temp->next=list2;
            swap(list1, list2);
        }
        return res;
    }  */
};