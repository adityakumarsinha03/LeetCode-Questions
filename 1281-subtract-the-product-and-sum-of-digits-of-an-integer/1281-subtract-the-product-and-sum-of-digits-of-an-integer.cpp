class Solution {
public:
    int subtractProductAndSum(int n) {
        long long sum=0, prod=1;
        while(n>0){
            int digit = n%10;
            sum+=digit;
            prod*=digit;
            n/=10;
        }
        return prod-sum;
    }
};