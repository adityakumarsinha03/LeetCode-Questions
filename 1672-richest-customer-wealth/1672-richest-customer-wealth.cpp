class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row=accounts.size();
        int col=accounts[0].size();
        int sum=0,ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                sum+=accounts[i][j];
            }
            ans=max(ans,sum);
            sum=0;
        }
        return ans;
    }
};