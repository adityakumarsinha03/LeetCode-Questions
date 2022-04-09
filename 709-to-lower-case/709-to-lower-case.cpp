class Solution {
public:
    string toLowerCase(string s) {
        string str="";
        for(int i=0;i<s.size();i++){
             //str+=tolower(s[i]);
            if(s[i]>='A' && s[i]<='Z'){
                str+=(s[i]+'a'-'A');
            }else{
                str+=s[i];
            }
        }
        return str;
    }
};