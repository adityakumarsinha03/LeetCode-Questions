class Solution {
public:
    long long nCr(long long n, long long r){
       r= min(r, n-r);
       long long res=1;
       for(int i=0;i<r;i++){
           res*=(n-i);
           res/=(i+1);
       }
        return res;
    }
    
    int uniquePaths(int m, int n) {

        // return nCr(n+m-2, m-1);
         return nCr(n+m-2, n-1);
    }
};