class Solution {
public:
     bool isPalindrome(string s) {
        int i=0, j=s.length()-1;
        while(i<j){
            if(!isalnum(s[i]) )
                i++;
            else if(!isalnum(s[j]) )
                j--;
            else if(tolower(s[i]) != tolower(s[j]))
                return false;
            else
                i++,j--;
        }
         return true;
     }
    
  /*  bool isPalindrome(string s) {
        string str;
        char temp;
        for(int i=0;i<s.size();i++){
            
                if(s[i]>='A' && s[i]<='Z'){
                    //temp=tolower(s[i]);
                    temp=s[i]+'a'-'A';
                    str.push_back(temp);
                }else if(s[i]>='a' && s[i]<='z'){
                    str.push_back(s[i]);
                }else if(s[i]>='0' && s[i]<='9'){
                    str.push_back(s[i]);
                }
            }
        
       int i=0, j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j])
                return false;
            i++,j--;
        }
        return true;
        
    }  */
};