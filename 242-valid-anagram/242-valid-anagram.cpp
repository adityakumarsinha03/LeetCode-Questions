class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        
        unordered_map<char,int>um1, um2;
        for(int i=0;i<s.size();i++){
            um1[s[i]]++;
            um2[t[i]]++;
        }
        return um1==um2;
    }
    /*
    bool isAnagram(string s, string t) {
              
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s==t;            
    }   */
};