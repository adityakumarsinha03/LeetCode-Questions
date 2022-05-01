// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int superPrimes(int n) {
	    vector<bool> isPrime(n + 1, true);
	    isPrime[0] = isPrime[1] = false;
	    for(int i = 2; i * i <= n; i++) {
	        if(!isPrime[i]) continue;
	        for(int j = i * i; j <= n; j += i) isPrime[j] = false;
	    }
	    
	    int ans = 0;
	    for(int i = 5; i <= n; i++) ans += isPrime[i] && isPrime[i - 2];
	    
	    return ans;
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
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends