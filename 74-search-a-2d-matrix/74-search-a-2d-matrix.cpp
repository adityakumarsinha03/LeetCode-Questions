class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size(), n=matrix[0].size();
        int low=0, high=(n*m)-1;
        int mid, i, j;
        while(low<=high){
            mid= (low+high)/2;
            i= mid/n;
            j= mid%n;
            
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]< target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};