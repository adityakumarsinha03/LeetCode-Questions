// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    {  
        int n=nums.size();
        vector<int> ahead(k+1,0);
        vector<int> curr(k+1,0);
        
        for(int i=0;i<=nums[n-1];i++)
         ahead[i]=i*i;
         for(int ind=n-2;ind>=0;ind--)
         {
             for(int rl=0;rl<=k;rl++)
             {
                   if(nums[ind]<rl)
                   {
                       int take=ahead[rl==k?rl-nums[ind]:rl-nums[ind]-1];
                       int notTake=rl*rl+ahead[k-nums[ind]];
                       curr[rl] = min(take,notTake);
                   }
                   else
                   {
                       curr[rl] = rl*rl+ahead[k-nums[ind]];
                   }
             }
             ahead=curr;
         }
         return curr[k];
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends