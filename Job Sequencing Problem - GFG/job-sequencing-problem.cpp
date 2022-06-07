// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool compare(Job j1, Job j2) {
        if(j1.profit>j2.profit) return true;
        else  return false;
        
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, compare);
        int mx=0;
        for(int i=0; i<n;i++){
            mx= max(mx, arr[i].dead);
        }
        vector<int> slot(mx+1, -1);
        int profit=0, count=0;
        for(int i=0; i<n;i++){
            int last= arr[i].dead;
            while(last>0){
                if(slot[last]==-1){
                    slot[last]= arr[i].id;
                    profit+=arr[i].profit;
                    count++;
                    break;
                }else{
                    last--;
                }
            }
        }
        vector<int> ans(2,0);
        ans[0]=count;
        ans[1]=profit;
        return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends