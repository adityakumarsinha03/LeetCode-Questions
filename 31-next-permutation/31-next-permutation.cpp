class Solution {
public:
  /*  void nextPermutation(vector<int>& nums) {
       int n= nums.size(), k, l;
       for(k=n-2;k>=0;k--){
           if(nums[k]<nums[k+1]){
               break;
           }
       }
       if(k<0){
           reverse(nums.begin(), nums.end());
       }else{
           for(l=n-1;l>k;l--){
               if(nums[l]>nums[k]){
                   break;
               }
           }
           swap(nums[k], nums[l]);
           reverse(nums.begin()+k+1, nums.end());
       }   
    }  */
    
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());     //in-built fun
    }
    
    /*void nextPermutation(vector<int>& nums) {
        vector<int> temp = nums;
        bool flag=0;
        sort(nums.begin(), nums.end());
        do{
            if(flag){
                return ;
            }
            if(nums==temp)
                flag=1;
        }while(next_permutation(nums.begin(), nums.end())); 
    }  */
    
};