class Solution {
public:
    static bool compare(vector<int> b1, vector<int> b2){
        return b1[1] > b2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int remSize= truckSize, res=0;
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=remSize){
                res+= (boxTypes[i][1]*boxTypes[i][0]);
                remSize-=boxTypes[i][0];
            }else{
                res+= remSize*boxTypes[i][1];
                break;
            }
        }
        return res;
    }
};