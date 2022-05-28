// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
    unordered_map<int, int> um;
    int prefix_sum=0, res=0;
    for(int i=0;i<n;i++){
        prefix_sum+=A[i];
        if(prefix_sum==0){
            res= max(res, i+1);
        }else if(um.find(prefix_sum)!=um.end()){
            res= max(res, i-um[prefix_sum]);
        }else{
            um[prefix_sum]=i;
        }
    }
    return res;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends