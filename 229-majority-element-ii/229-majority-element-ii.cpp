class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int num1= -1, num2= -1, count1=0, count2=0;
        for(auto num : nums){
            if(num==num1)
                count1++;
            else if(num==num2)
                count2++;
            else if(count1==0)
                num1=num, count1=1;
            else if(count2==0)
                num2=num, count2=1;
            else
                count1--, count2--;
        }
        
        count1 = count2 = 0;
        for(auto num : nums){
            if(num==num1)
                count1++;
            else if(num==num2)
                count2++;
        }
        vector<int>ans;
        if(count1 > n/3)
            ans.push_back(num1);
        if(count2 > n/3)
            ans.push_back(num2);
        
        return ans;
    }
};