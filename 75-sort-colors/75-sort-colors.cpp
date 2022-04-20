class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, j=nums.size()-1, k=0;
        while(k<=j){
            if(nums[k]==0){
                swap(nums[i], nums[k]);
                k++, i++;
            }else if(nums[k]==1){
                k++;
            }else{
                swap(nums[k], nums[j]);
                j--;
            }
        }
    }
};