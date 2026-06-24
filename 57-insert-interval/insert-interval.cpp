class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> final;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        final.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>final.back()[1]){
                final.push_back(intervals[i]);
            }else{
                vector<int>temp={final.back()[0],max(intervals[i][1],final.back()[1])};
                final.pop_back();
                final.push_back(temp);
            }
        }
        return final;
    }
};