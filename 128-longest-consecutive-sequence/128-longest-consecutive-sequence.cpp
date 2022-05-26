class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num: nums){
            s.insert(num);
        }
        
        int mx=0, count;
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i]-1)==0){
                count=1;
                while(1){
                    if(s.count(nums[i]+count)){
                        count++;
                    }else{
                        break;
                    }
                }
                mx= max(mx, count);
            }
        }
        return mx;
    }
};