class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int s=-1, res=0, i=0;
        for(i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(s==-1)
                    s=i;
            }else{
                if(s!=-1)
                res= max(res, i-s);
                s=-1;
            }     
        }
        if(s!=-1)
            res= max(res, i-s);
        return res;
    }
};