class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        int l=0, r=0, ans=0;
        while(r<s.size()){
            if(mpp[s[r]]!=-1){
                l= max(mpp[s[r]]+1, l);
            }
            mpp[s[r]]=r;
            ans= max(ans, r-l+1);
            r++;
        }
        return ans;
    }    
    
    /*  O(2n) || O(n)
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int ans=0, l=0;
        for(int r=0; r<s.size(); r++){     //travelling in outer loop 
            if(set.find(s[r])!=set.end()){     //dublicate element found
                while(l<r && set.find(s[r])!=set.end() ){
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
            ans=max(ans, r-l+1);
        }
        return ans;
    } */
    
    /*  Sliding Window - Aditya Verma  ->  O(2n) || O(n)
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>um;
        int mx=0,i=0,j=0;
        while(j<s.size()){
            um[s[j]]++;
            if(um.size()==j-i+1){
                mx=max(mx,j-i+1);
                j++;
            }else if(um.size()<j-i+1){
                while(um.size()<j-i+1){
                    um[s[i]]--;
                    if(um[s[i]]==0)
                        um.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return mx;
    }  */
};