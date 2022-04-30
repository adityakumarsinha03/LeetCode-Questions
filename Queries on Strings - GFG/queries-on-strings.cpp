// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
   vector<int>ans;
   for(int i=0;i<Query.size();i++)
   {
       int index1=Query[i][0]-1;
       int index2=Query[i][1]-1;
       int arr[26]={0}; 
       int count=0;
       for(int j=index1;j<=index2;j++)
       {
           
           int num=0;
           num=str[j]-'a';
           arr[num]++;
       }
     
       for(int k=0;k<26;k++)
       {
           if(arr[k]>0)
           {
               count++;
           }
       }
       ans.push_back(count);
   }
   return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends