class Solution {
public:
    
  /*1. Basic idea of the algorithm is if we cancel out each occurrence of an element e,
with all the other elements that are different from e then e will exist till end if it is a majority element. 
2. Below code loops through each element and maintains a count of the element that has the potential of being the majority element.
3. If next element is same then increments the count, otherwise decrements the count.
4. If the count reaches 0 then update the potential index to the current element and sets count to 1.*/
    
    int majorityElement(vector<int>& nums) {
       int ans=nums[0], count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ans){
                count++;
            }else{
                count--;
            }
            
            if(count==0){
                ans=nums[i];
                count=1;
            }
        }
        return ans;
    } 
};