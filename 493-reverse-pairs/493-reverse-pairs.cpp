class Solution {
public:
  int Merge(vector < int > & nums, int low, int mid, int high) {
  int total = 0;
  int j = mid + 1;
  for (int i = low; i <= mid; i++) {
    while (j <= high && nums[i] > 2LL * nums[j]) {
      j++;
    }
    total += (j - (mid + 1));
  }

  vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;
}
int MergeSort(vector < int > & nums, int low, int high) {

  if (low >= high) return 0;
  int mid = (low + high) / 2;
  int inv = MergeSort(nums, low, mid);
  inv += MergeSort(nums, mid + 1, high);
  inv += Merge(nums, low, mid, high);
  return inv;
}
int reversePairs(vector < int > & arr) {
  return MergeSort(arr, 0, arr.size() - 1);
}

    /* int Merge(vector<int>nums, int low, int mid, int high){
        int total= 0, i, j= mid;
        // O(n)
        long long int two=2;
        for(int i=low; i<mid; i++){
            while(j<=high && ( nums[i] > (long)2*nums[j] ) ){   //overflow if not LL
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
        
        return total;
    }
    
    int mergeSort(vector<int>nums, int low, int high){
        int inv= 0;
        if(low<=high){
            int mid= (low+high) /2;
           inv+= mergeSort(nums, low, mid);
           inv+= mergeSort(nums, mid+1, high);
           inv+= Merge(nums, low, mid+1, high);
        }
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }   */
};