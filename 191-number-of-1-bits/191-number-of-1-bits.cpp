class Solution {
public:
    int hammingWeight(uint32_t n) {
		// support variables
        int res = 0;
        while (n) {
            // updating res
			res += n & 1;
			// reducing n
           n >>= 1 ;             //n = n>>1  // n = n/2;
        }
        return res;
    }
};