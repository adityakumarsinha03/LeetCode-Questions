class Solution {
public:
    unordered_map<int,int>um;
    bool check(string a, string b){
        for(int i=0;i<min(a.size(), b.size());i++){
            if(a[i]!=b[i]){
                if(um[b[i]]<um[a[i]]){
                    return false;
                }else{
                    return true;
                }
            }
        }
        return a.size()<=b.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        
        for(int i=0;i<order.size();i++){
            um[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
            if(!check(words[i],words[i+1]))
                return false;
        }
        return true;
    }
};