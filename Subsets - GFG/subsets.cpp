// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      void subset(int x,vector<int>& A,vector<int>& temp, vector<vector<int> >& res)
   {
       res.push_back(temp);
       for(int i=x;i<A.size();i++)
       {
           temp.push_back(A[i]);
           subset(i+1,A,temp,res);
           temp.pop_back();
       }
   }
   vector<vector<int> > subsets(vector<int>& A)
   {
       vector<vector<int> > res;
       vector<int> temp;
       subset(0,A,temp,res);
       sort(res.begin(),res.end());
       return res;
   }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends