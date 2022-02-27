// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
const int INF = 1e9+7;

struct hashpair {
public:
	template<typename T, typename U>
	size_t operator () (const pair<T, U>& p) const {
		return hash<T>()(p.first) ^ hash<U>()(p.second);
	}
};

class Solution {
  public:
    int mostBalloons(int N, pair<int, int> arr[]) {
        if(N < 3) return N;
        
        unordered_map<pair<int, int>, int, hashpair> mem;
        int res = 2;
        
        for(int i=0; i<N-1; i++) {
            int f = 1;
            for(int j=i+1; j<N; j++) {
                int dy = arr[j].second-arr[i].second, dx = arr[j].first-arr[i].first;
                if(dy == 0 and dx == 0) f++;
                else if(dy == 0) mem[{0, INF}]++;
                else if(dx == 0) mem[{INF, 0}]++;
                else {
                    if(dy < 0 and dx < 0) dy = abs(dy), dx = abs(dx);
                    else if(dy < 0 or dx < 0) dy = -abs(dy), dx = abs(dx);
                    int GCD = __gcd(abs(dy), abs(dx));
                    mem[{dy/GCD, dx/GCD}]++;
                }
            }
            for(auto &p : mem)
                res = max(res, p.second+f);
            mem.clear();
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends