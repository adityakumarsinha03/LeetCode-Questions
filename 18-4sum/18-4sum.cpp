class Solution {
public:
    // TC: O(n^3 * log n)   //SC: O(m*4)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int x= target- ((long long)nums[i]+ (long long)nums[j]+ (long long)nums[k]);
                    if(binary_search(nums.begin()+k+1, nums.end(), x)){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(x);
                        sort(v.begin(), v.end());  //so that set will contain the element in sorted order and repetetion can be prevented
                        s.insert(v);
                    }
                }
            }
        }
        vector<vector<int>> res(s.begin(), s.end());   //copy from set to vector
        return res;
    }
};