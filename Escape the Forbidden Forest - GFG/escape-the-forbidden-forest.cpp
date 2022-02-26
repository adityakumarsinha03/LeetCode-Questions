// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends
class Solution
{
    public:
    int build_bridges(string s1, string s2)
    {
        // code here
        int n = s1.size(),m = s2.size();
        int ans = LCS(s1,s2,n,m);
        return ans;
    }
    int LCS(string s1,string s2,int n,int m){
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //dp[i][j] = longest common subsequence for lengths i in s1 and j in s2
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i == 0 || j==0){
                    //base cases
                    dp[i][j] = 0;
                    continue;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends