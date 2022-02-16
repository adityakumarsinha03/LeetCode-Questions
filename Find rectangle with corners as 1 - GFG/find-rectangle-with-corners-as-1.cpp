// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map>
#include <unordered_set>
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool ValidCorner(const vector<vector<int> >& a)
    {
        // Your code goes here
        int n = a.size();
        int m = a[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==1){
                for(int k = 1;k<m-j;k++){
                    if(a[i][j+k]==1){
                        for(int x=1;x<n-i;x++){
                            if(a[i+x][j+k]==1&&a[i+x][j]==1)
                            return true;
                        }
                    }
                }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int row, col;
        cin>> row>> col;

        vector<vector<int> > matrix(row);
            
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        if (ob.ValidCorner(matrix)) 
            cout << "Yes\n"; 
        else
            cout << "No\n"; 
    }

    return 0;
} 


  // } Driver Code Ends