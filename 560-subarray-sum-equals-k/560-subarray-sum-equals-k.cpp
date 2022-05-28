class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int sum=0, count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            }if(um.find(sum-k)!=um.end()){
                count+=um[sum-k];
            }
            um[sum]++;
        }
        return count;
    }
};