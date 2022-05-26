class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num: nums){
            s.insert(num);
        }
        
        int mx=0;
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i]-1)==0){
                int currentNum= nums[i];
                int currentStreak= 1;
                while(s.count(currentNum+1)){
                    currentNum+=1;
                    currentStreak+=1;
                }
                mx= max(mx, currentStreak);
            }
        }
        return mx;
    }
};