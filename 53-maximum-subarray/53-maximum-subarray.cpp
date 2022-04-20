class Solution {
public:
    //KADANE'S ALGORITHM
    int maxSubArray(vector<int>& nums) {
        int mx=INT_MIN, sum=0;
        //for(int i=0;i<nums.size();i++){
        for(auto it : nums){
            //sum+=nums[i];
            sum+=it;
            mx=max(mx, sum);
        
            if(sum<0) sum=0;
        }
    
        return mx;
    }
};