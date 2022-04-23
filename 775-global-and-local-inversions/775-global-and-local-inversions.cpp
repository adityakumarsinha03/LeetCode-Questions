class Solution {
public:
    long long merge(vector<int>& arr, long long *temp, long long low, long long mid, long long high){
	int i=low, j=mid, k=low, inv_count=0;
	while(i<mid && j<=high){
		if(arr[i]<arr[j]){
			temp[k++]=arr[i++];
		}else{
			temp[k++]=arr[j++];
			inv_count += (mid - i);
		}
	}
	while(i<mid){
		temp[k++]=arr[i++];
	}
	while(j<=high){
		temp[k++]=arr[j++];
	}
	for(int i=low;i<=high;i++){
		arr[i]=temp[i];
	}
 	return inv_count;
    }

long long merge_sort(vector<int>& arr, long long *temp, long long low, long long high){
	int inv_count=0;
	if(low<high){
	  int mid= (low+high)/2;
	  inv_count += merge_sort(arr, temp, low, mid);
	  inv_count += merge_sort(arr, temp, mid+1, high);
		
	  inv_count += merge(arr, temp, low, mid+1, high);
	}
	return inv_count;
}

int local(vector<int>& nums, int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1])
            count++;
    }
    return count;
}    
    
    
    bool isIdealPermutation(vector<int>& nums) {
        int n= nums.size();
        long long temp[n];
        int localInversion = local(nums, n);
        int globalInversion = merge_sort(nums, temp, 0, n-1);
        
        if(globalInversion == localInversion)
            return true;
        else
            return false;
    }
};

