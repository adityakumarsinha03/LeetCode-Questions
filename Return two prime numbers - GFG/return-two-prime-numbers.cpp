// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<int> twosum( bool primes[],int n)
    {
        vector<int> ans;
        for(int i=2;i<=n;i++)
        {
            if(primes[i]==1&&primes[n-i]==1)
            {
                ans.push_back(i);
                ans.push_back(n-i);
                return ans;
            }  
        }
        return ans;
    }
    vector<int> primeDivision(int n){
       bool primes[n+1];
       memset(primes,true,sizeof(primes));
       primes[0]=false;primes[1]=false;
       
       for(int i=2;i<=n;i++)
       {
           if(primes[i])
           {
               for(int j=2;j<=n/i;j++)
                    primes[i*j]=false;
           }
       }
      return twosum(primes,n);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends