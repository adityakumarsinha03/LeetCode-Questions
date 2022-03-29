class Solution {
public:
  int findDuplicate(vector<int>& nums) {
      for(int i=0;i<nums.size();i++){
          int index = abs(nums[i])-1;
          nums[index] *= -1;
          if(nums[index]>0){
              return index+1;
          }
      }
      return -1;
   }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   /* 
    
    int findDuplicate(vector<int>& nums) {
    for(int i=0;i<nums.size();i++){
        int index = abs(nums[i])-1;
        nums[index] *= -1;
        
        if(nums[index]>0){
            return index+1;
        }
    }
       return -1;
   }
    */
    
  /*  int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> um;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(um[nums[i]]==1){
                ans=nums[i];
                break;
            }else{
                um[nums[i]]++;
            }
        }
        return ans;
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