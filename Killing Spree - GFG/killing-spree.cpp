// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
       long long int killinSpree(long long int n)
   {
       // Code Here
        if(n==1)
           return n;
           
        long long int  st_p=n;
        long long int ans=0;
        long long int st_i;
        long long int i=1;
        
       while(i<n){
           st_i=i*i;
           st_p-=st_i;
           if(st_p==0 || st_p < (i+1)*(i+1)){
               ans=i;
               break;
           }
           i++;
       }
       return ans;
   }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends