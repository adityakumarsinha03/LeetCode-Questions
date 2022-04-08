class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string output="";
        int i=0;
        for(;i<min(word1.size(), word2.size());i++){
            output+=word1[i];
            output+=word2[i];
        }
        while(i<word1.size()){
            output+=word1[i++];
        }
        while(i<word2.size()){
            output+=word2[i++];
        }
        return output;
    }
};