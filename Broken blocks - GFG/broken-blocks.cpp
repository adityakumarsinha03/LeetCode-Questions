// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

int MaxGold(vector<vector<int>>&mat)
{  
  int n=mat.size();
  int m=mat[0].size();
  vector<vector<int>>dp(n,vector<int>(m,-1));
  int ans=0;
  
  for(int i=0;i<m;i++)
  {   
      if(mat[0][i]!=-1)
      {
          dp[0][i]=mat[0][i];
          ans=max(ans,dp[0][i]);
      }
  }
  
  for(int i=1;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {   
          if(mat[i][j]!=-1)
          {   
              int m1=INT_MIN,m2=INT_MIN,m3=INT_MIN;
              
              if( j-1>=0 and mat[i-1][j-1]!=-1 and dp[i-1][j-1]!=-1)
              m1=dp[i-1][j-1]+mat[i][j];
              
              if( j>=0 and mat[i-1][j]!=-1 and dp[i-1][j]!=-1)
              m2=dp[i-1][j]+mat[i][j];
              
              if( j+1<m and mat[i-1][j+1]!=-1 and dp[i-1][j+1]!=-1)
              m3=dp[i-1][j+1]+mat[i][j];
              
              
              dp[i][j]=max(dp[i][j],max(m1 ,max(m2,m3)));
              ans=max(ans,dp[i][j]);
          }
          
      }
  }
  
  return ans;
  
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends