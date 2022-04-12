#include<bits/stdc++.h>
class Solution {
public:
    static bool compare(pair<int,int>&a, pair<int,int>&b){
        if(a.second!=b.second)
            return a.second < b.second;
        else
            return a.first < b.first;
    }
    int count_1(int n){
        int count=0;
        while(n){
            count += (n&1);
            n = n>>1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>v;
        for(int i=0;i<arr.size();i++){
            int c = count_1(arr[i]);
            v.push_back({arr[i],c});
        }
        sort(v.begin(), v.end(), compare);
        vector<int>ans;
        for(int i=0; i<v.size(); i++){
            ans.push_back(v[i].first);
         }
        return ans;
    }
};