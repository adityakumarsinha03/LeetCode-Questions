// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    class meeting{
        public:
        int start;
        int end;
        int pos;
    };
    static bool compare(meeting m1, meeting m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.pos < m2.pos) return true;
        else return false;
    }
    int maxMeetings(int s[], int e[], int n)
    {
        meeting m[n];
        //int *m= new meeting[n];
        for(int i=0; i<n; i++){
            m[i].start= s[i];
            m[i].end= e[i];
            m[i].pos= i+1;
        }
        sort(m, m+n, compare);
        vector<int> ans;
        int limit= m[0].end;
        ans.push_back(m[0].pos);
        for(int i=1;i<n;i++){
            if(m[i].start>limit){
                ans.push_back(m[i].pos);
                limit= m[i].end;
            }
        }
        return ans.size();
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends