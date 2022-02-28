class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        if(nums.size()==0)
            return ans;
        
        int prev=nums[0], j=0, count=1, i;
        for(i=1;i<nums.size();i++){
            if(nums[i]!=prev+1){
                if(count!=1){
                string s = to_string(nums[j])+"->"+to_string(nums[i-1]);
                ans.push_back(s);
                j=i, count=0;
                }
                else{
                string s = to_string(nums[j]);
                ans.push_back(s);  
                j=i, count=0;        
                }
            }
           
            prev=nums[i];
            count++;
        }
        
                if(count!=1){
                string s = to_string(nums[j])+"->"+to_string(nums[i-1]);
                ans.push_back(s);
                }
                else{
                string s = to_string(nums[j]);
                ans.push_back(s);  
                }
        
        return ans;
    }
};