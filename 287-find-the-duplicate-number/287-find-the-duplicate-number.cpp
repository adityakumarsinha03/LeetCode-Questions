class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int slow= nums[0];
    int fast= nums[0];
      do{
          slow=nums[slow];
          fast=nums[nums[fast]];
      }while(slow!=fast);
      
      fast=nums[0];
      while(slow!=fast){
          slow=nums[slow];
          fast=nums[fast];
      }
      return slow;
   } 
    
    
  /*    //Will modify the array
  int findDuplicate(vector<int>& nums) {
    for(int i=0;i<nums.size();i++){
        int index = abs(nums[i])-1;
        nums[index] *= -1;
        
        if(nums[index]>0){
            return index+1;
        }
    }
       return -1;
   }  */
     
    
    
  /*   //Will not work if [2,2,2,2,2]
    int findDuplicate(vector<int>& nums) {
        int ans=0, n=nums.size();
        for(int i=1;i<=n-1;i++){
            ans=ans^i;
        }
        for(int i=0;i<n;i++){
            ans=ans^nums[i];
        }
        return ans;
    }   */
};