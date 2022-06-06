class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n= nums.size();
        for(int i=0;i<n-2;i++){
            int req= -nums[i];
            int lo=i+1, hi=n-1;
            while(lo<hi){
                if(nums[lo]+nums[hi] ==req){
                    res.push_back({nums[i],nums[lo],nums[hi]});
                    while(lo<hi &&  nums[lo+1]==nums[lo]){
                        lo++;
                    }
                    while(lo<hi && nums[hi-1]==nums[hi]){
                        hi--;
                    }
                    lo++, hi--;
                }else if(nums[lo]+nums[hi] <req){
                    while(lo<hi && nums[lo+1]==nums[lo]){
                        lo++;
                    }
                    lo++;
                }else{
                    while(lo<hi && nums[hi-1]==nums[hi]){
                        hi--;
                    }
                    hi--;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
        }
        return res;
    }
};