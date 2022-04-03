class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<int> v(points.size(),INT_MAX);
        for(int i=0;i<points.size();i++){
                if(points[i][0]==x || points[i][1]==y){
                    v[i]=abs(x-points[i][0])+abs(y-points[i][1]);
                }
        }
        int index=-1, mn=INT_MAX;
        for(int i=0;i<v.size();i++){
                if(v[i]<mn){
                    mn=v[i];
                    index=i;
                }
        }
        return index;
    }
};