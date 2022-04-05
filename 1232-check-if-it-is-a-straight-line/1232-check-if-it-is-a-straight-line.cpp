class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
      int  ydiff = coordinates[1][1] - coordinates[0][1];    //y1-y0  
      int  xdiff = coordinates[1][0] - coordinates[0][0];    //x1-x0
        
        for(int i=0;i<coordinates.size();i++){
            int y = coordinates[i][1] - coordinates[0][1];  //y-y0
            int x = coordinates[i][0] - coordinates[0][0];  //x-x0
            
            //   y-y0/x-x0 == y1-y0/x1-x0
            if(y * xdiff != x * ydiff)
                return false;
        }
        return true;
    }
};