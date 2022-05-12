// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool p(vector<vector<int>>& grid, int n, int m, int i, int j){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return false;
        if(grid[i][j] == 2) return true;
        
        
        grid[i][j] = 0;
        bool f = p(grid, n, m, i - 1, j) || p(grid, n, m, i, j + 1) || p(grid, n, m, i + 1, j) || p(grid, n, m, i, j - 1);
        grid[i][j] = 3;
        
        return f;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return p(grid, n, m, i, j);
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends