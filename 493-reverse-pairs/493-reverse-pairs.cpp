class Solution {
public:
      int Merge(vector<int> &nums, int low, int mid, int high){
        int total= 0, i, j= mid;
        // O(n)
        for(int i=low; i<mid; i++){
            while(j<=high && ( nums[i] > 2LL * nums[j] ) ){   //overflow if not LL
                j++;
            }
            total+= j-mid;
        }
        
        vector<int> temp;
        i=low, j=mid;
        while(i<mid && j<=high){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<mid){
            temp.push_back(nums[i++]);
        }
        while(j<=high){
            temp.push_back(nums[j++]);
        }
        
        for(int i=low; i<=high; i++){
            nums[i]= temp[i-low];
        }
        return total;
    }
    
    int mergeSort(vector<int> &nums, int low, int high){
        int inv= 0;
        if(low<high){
           int mid= (low+high) /2;
           inv+= mergeSort(nums, low, mid);
           inv+= mergeSort(nums, mid+1, high);
           inv+= Merge(nums, low, mid+1, high);
        }
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }   
};