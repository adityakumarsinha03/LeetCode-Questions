class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size()==0)
            return mergedIntervals;
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];
        for(auto it: intervals){
            if(it[0] <= tempInterval[1]){
                tempInterval[1]=max(it[1], tempInterval[1]);
            }else{
                mergedIntervals.push_back(tempInterval);
                tempInterval=it;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
    
    /*vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int start=intervals[0][0], end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=end){
                end=max(end, intervals[i][1]);
            }else{
                res.push_back({start, end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        res.push_back({start, end});
        return res;
    }*/
};