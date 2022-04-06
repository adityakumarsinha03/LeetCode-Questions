// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool comp(string s, string r)
   {
       return s.size()<r.size() ;
   }
   string LCP(string arr[], int n)
   {
       // code here
       sort(arr,arr+n,comp);
       string ans = arr[0];
       
       for(int i=1 ; i<n ;i++ )
       {
           while(arr[i].find(ans)!=0)
           {
               ans.pop_back();
           }
       }
       return ans=="" ? "-1" : ans;
   }
};

// { Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends