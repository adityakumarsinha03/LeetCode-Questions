class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0, i=0;
        int prev=nums[i];
        for(i=1;i<nums.size();i++){
            if(nums[i]!=prev){
                nums[k]=prev;
                k++;
                prev=nums[i];
            }
        }
        nums[k]=prev;
        return k+1;
    }
};