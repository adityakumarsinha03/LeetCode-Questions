class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int ans;
        for(int i=0;i<n-1;i++){
            ans = (ans*26) + (columnTitle[i]-'A'+1);
        }
        ans = (ans*26)+(columnTitle[n-1]-'A'+1);
        return ans;
    }
};