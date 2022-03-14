// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int biGraph(int arr[], int n, int e) {
        
        
        if(n<=2){
            return 1;
        }
        vector<int> degree(n,0);
        
        vector<int> adj[n];
        for(int i=0; i<2*e; i+=2){
            int u = arr[i],v =arr[i+1];
            degree[u] += 1;
            degree[v] += 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        vector<int> tin(n,-1);//time of insertion
        vector<int> low(n,-1);//lowest possible time to reach
        int timer = 0;
        vector<int> isArticulation(n,0);
        bool ok = false;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(ok){
                    //Connected components > 1
                    return 0;
                }
                dfs(i,-1,vis,tin,low,timer,adj,isArticulation,degree);
                ok = true;
            }
        }
        for(int i=0; i<n; i++){
            if(isArticulation[i] == 1){
                return 0;
            }
        }
        return 1;
    }
    void dfs(int node,int parent,vector<int> &vis,vector<int> &tin,vector<int> &low,int &timer,vector<int> adj[],vector<int> &isArticulation,vector<int> &degree){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto it:adj[node]){
            if(it == parent){
                continue;
            }
            if(!vis[it]){
                dfs(it,node,vis,tin,low,timer,adj,isArticulation,degree);
                low[node] = min(low[node],low[it]);
                if(low[it] > tin[node]){
                    //compulsorily must visit from parent i.e node
                    //node<<" "<<it //edge is bridge
                    if(degree[it] > 1){
                        isArticulation[it] = 1;
                    }
                    if(degree[node] > 1){
                        isArticulation[node] = 1;
                    }
                    
                    
                }
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}  // } Driver Code Ends