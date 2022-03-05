class Solution {
public:
    /*  vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++){
            string s = "";
            if(i%3==0)
                s+="Fizz";
            if(i%5==0)
                s+="Buzz";
            if(s.size()==0)
                s+=to_string(i);
            
            ans.push_back(s);
        }
        return ans;
    }
    */
    
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        int fizz=0, buzz=0;
        for(int i=1;i<=n;i++){
            fizz++;
            buzz++;
            if(fizz==3 && buzz==5){
                ans.push_back("FizzBuzz");
                fizz=0, buzz=0;
            }else if(fizz==3){
                ans.push_back("Fizz");
                fizz=0;
            }else if(buzz==5){
                ans.push_back("Buzz");
                buzz=0;
            }else{
                ans.push_back(to_string(i));
            }    
        }
        return ans;
    }
};