// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node* swap(Node* ptr1,Node* ptr2,Node* head)   //fuction for swap
{
   Node* p=head;
   Node*q=head;
   while(p->next!=ptr1)
   {
       p=p->next;
   }
   if(ptr2==head)
   {
       ptr1->next=ptr2->next;
       ptr2->next=NULL;
       p->next=ptr2;
       head=ptr1;
       return head;
   }
   while(q->next!=ptr2)
   {
       q=q->next;
   }
   if(ptr2->next==ptr1)
   {
       ptr2->next=ptr1->next;
       q->next=ptr1;
       ptr1->next=ptr2;
       return head;
   }
    
   q->next=ptr1;
   Node * temp=ptr1->next;
   ptr1->next=ptr2->next;
   ptr2->next=temp;
   p->next=ptr2;
   free(temp);
   return head;
}
Node *swapkthnode(Node* head, int num, int K)
{
   if(K>num||(num%2==1&&K==(num/2)+1))
   {
       return head;
   }
   int i=0;
   Node* ptr1=head;
   Node* ptr2=head;
   while(i<(num-K))
   {
       ptr1=ptr1->next;
       i++;
   }
   i=0;
   while(i<(K-1))
   {
       ptr2=ptr2->next;
       i++;
   }
   Node* ans;
   if(K==num)
   {
       ans=swap(ptr2,ptr1,head);
   }
   else ans=swap(ptr1,ptr2,head);
   
   
   return ans;
}