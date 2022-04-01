class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(i+2<s.size() && s[i+2]=='#'){
                string temp = s.substr(i,2);
                int n = stoi(temp);
                ans+=(char(n+'a'-1));
                i+=2;
            }else{
                //ans+=(char(s[i]+'a'-1));
                 ans += char(s[i]-'0'-1+'a');
            }
        }
        return ans;
    }
};