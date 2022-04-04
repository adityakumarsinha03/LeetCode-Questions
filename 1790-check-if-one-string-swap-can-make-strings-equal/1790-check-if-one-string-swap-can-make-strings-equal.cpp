class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count=0, a, b;
        for(int i=0;i<s1.size();i++){
            if(count==0 && s1[i]!=s2[i]){
                a=s1[i], b=s2[i];
                count++;
            }else if(count==1 && s1[i]!=s2[i]){
                if(b!=s1[i] || a!=s2[i]){
                    return false;
                }
                count++;
            }else if(count==2 && s1[i]!=s2[i]){
                return false;
            }
        }
        if(count==0 || count==2)
          return true;
        else
          return false;  
    }
};