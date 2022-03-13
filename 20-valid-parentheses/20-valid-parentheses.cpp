class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;              
        char topE;
        for(int i=0;i<s.length();i++){
            if( s[i] == '(' || s[i] == '{' || s[i] == '[' ){  
                bracket.push(s[i]);
            }
            else{
                if(bracket.empty())     
                    return false;
                topE = bracket.top();   
                bracket.pop();
                if( topE == '{' && s[i]!='}')   
                    return false;
                if( topE == '[' && s[i]!=']')
                    return false;
                if( topE == '(' && s[i]!=')')
                    return false;
            }
        }
        return bracket.empty();      
    }

};