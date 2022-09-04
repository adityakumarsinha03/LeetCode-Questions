class Solution {
public:
 vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            int se = target-nums[i];
            if(mp.find(se) != mp.end())
            {
                ans.push_back(i);
                ans.push_back(mp[se]);
                return ans;
            }
            else
                mp[nums[i]] = i;
        }
        return ans;
        
    }
};