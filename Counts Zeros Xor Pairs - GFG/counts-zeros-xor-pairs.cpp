// { Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}

// } Driver Code Ends


long long int cnt(long long int a){
    return (a*(a+1))/2;
}
long long int calculate(int a[], int n)
{
    long long int count = 0,tmp = 0;
    sort(a,a+n);
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            tmp++;
        }else{
            if(tmp>=1) count+=cnt(tmp);
            tmp = 0;
        }
    }
    if(tmp>=1) count+=cnt(tmp);
    return count;
}