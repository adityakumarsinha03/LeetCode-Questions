class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> um;
       vector<int> ans;
       for(int i=0;i<nums.size();i++){
           if(um.find(target-nums[i])!=um.end()){
               ans.push_back(um[target-nums[i]]);
               ans.push_back(i);
               return ans;
           }
               um[nums[i]]=i;
       }
       return ans;
   }
 /*   //Brute Force
  vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
           int req= target- nums[i]; 
           for(int j=i+1;j<nums.size();j++) 
           {
               if(nums[j]==req)
               {    ans.push_back(i);
                    ans.push_back(j);
                    break;
               }
           }
            
        }
    return ans;    
    }   */
};