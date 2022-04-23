class Solution {
public:
    
/*void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1, j=n-1, k=m+n-1;
    while(i>=0 && j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k--]=nums1[i--];
        }else{
            nums1[k--]=nums2[j--];
        }
    }
    while(j>=0){
        nums1[k--]=nums2[j--];
    }
}  */

//GAP METHOD    
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int gap=ceil((float)(m+n)/2);
    while(gap>0){
        int i=0, j=gap;
        while(j<(m+n)){
        if(j<m && nums1[i]>nums1[j]){
            swap(nums1[i], nums1[j]);
        }else if(j>=m && i<m && nums1[i]>nums2[j-m]){
            swap(nums1[i], nums2[j-m]);
        }else if(j>=m && i>=m && nums2[i-m]>nums2[j-m]){
            swap(nums2[i-m], nums2[j-m]);
        }
        i++, j++;    
        }
    if (gap == 1) {
      gap = 0;
    } else {
      gap = ceil((float) gap / 2);
    }
  }
    for(int i=0;i<n;i++){
        nums1[i+m]=nums2[i];
    }
}     
    
/* void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i=0;i<n;i++){
        nums1[m+i]=nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}   */    
    
};