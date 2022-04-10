class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(i+2<s.size() && s[i+2]=='#'){
               // string temp = s.substr(i,2);
               // int n = stoi(temp);
                int n = (s[i]-'0')*10 + (s[i+1]-'0');
                ans+=(char(n+'a'-1));
                i+=2;
            }else{
                 ans += char(s[i]-'0'-1+'a');
            }
        }
        return ans;
    }
};