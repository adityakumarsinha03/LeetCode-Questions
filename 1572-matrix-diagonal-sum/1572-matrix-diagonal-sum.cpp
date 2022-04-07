class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=mat[i][i];
        }
        for(int i=0;i<n;i++){
            if(i!=n-i-1)
            sum+=mat[n-i-1][i];
        }
        return sum;
    }
};