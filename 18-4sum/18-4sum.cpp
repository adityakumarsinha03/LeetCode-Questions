class Solution {
public:
    // TC: O(n^3)   //SC: O(1)
     vector<vector<int>> fourSum(vector<int>& nums, int target) {
     vector<vector<int>> res;     
         if(nums.empty())
             return res;
     int n=nums.size();      
     sort(nums.begin(), nums.end());    
         
     for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
             int target_2= target- (nums[i]+ nums[j]);
             int left= j+1, right= n-1;
             while(left<right){
                 int two_sum= nums[left]+ nums[right];
                 if(two_sum < target_2){
                     left++;
                 }else if(two_sum > target_2){
                     right--;
                 }else{
                //res.push_back({nums[i], nums[j], nums[left], nums[right]});
                      vector<int> quadruplet(4, 0); 
                     quadruplet[0]=nums[i];
                     quadruplet[1]=nums[j];
                     quadruplet[2]=nums[left];
                     quadruplet[3]=nums[right];
                     res.push_back(quadruplet);
                     //processing the duplicates of number 3
                     while(left<right && nums[left]== quadruplet[2]){
                         left++;
                     }
                     //processing the duplicates of number 4
                     while(left<right && nums[right]== quadruplet[3]){
                         right--;
                     }
                 }
             }
             //processing the duplicates of number 2
             while(j+1<n && nums[j]== nums[j+1])
                 j++;
         }
            //processing the duplicates of number 1
             while(i+1<n && nums[i]== nums[i+1])
                i++;
     }
         
     return res;
     }
    
    
    
    /*     // TC: O(n^3 * log n)   //SC: O(m*4)
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
    }   */
};