// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> ans;
        
        function<void(int, int)> fun = [&] (int start, int end) {
            if(start > end) return;
            
            int mid = start + end >> 1;
            ans.push_back(nums[mid]);
            fun(start, mid - 1);
            fun(mid + 1, end);
        };
        
        
        fun(0, nums.size() - 1);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends