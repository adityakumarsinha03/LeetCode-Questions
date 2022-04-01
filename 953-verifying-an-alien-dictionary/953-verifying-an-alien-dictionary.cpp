class Solution {
public: 
    unordered_map<int, int> um;
    
    bool checkOrder(string & a, string & b){
        for(int i=0; i< min(a.size(), b.size()); i++){
            if(um[a[i]] != um[b[i]]){
                if(um[a[i]] < um[b[i]])
                    return true;
                else
                    return false;
            }
        }
        
        //return a.size()<b.size();
        if(a.size()<=b.size())
            return true;
        else
            return false;
    }
    
    
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++){
            um[order[i]] = i;
        }
        for(int i=0; i<words.size()-1; i++){
            if(checkOrder(words[i], words[i+1]) == false)
                return false;
        }  
        return true;
    }
};