class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }    
    /*
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int k= s.size(), i=0;
        // for(auto it: s){
        //     nums[i++]= it;
        // }
        for(auto it= s.begin(); it!=s.end();it++){
            nums[i++]= *it;
        }
        return k;
    } */   
};