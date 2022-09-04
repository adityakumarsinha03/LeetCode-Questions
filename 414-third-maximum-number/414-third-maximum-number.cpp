class Solution {
public:
        int thirdMax(vector<int>& nums) {    
        sort(nums.begin(),nums.end());
        int c=distance(nums.begin(),unique(nums.begin(),nums.end()));
        unique(nums.begin(),nums.end());

        int n=nums.size();
        if(c==3){
            return nums[0];
        }else if(c<3){
         return nums[c-1];   
        }
        return nums[c-3];
    }
};