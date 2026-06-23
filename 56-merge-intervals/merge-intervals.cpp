class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> final;
        final.push_back(intervals[0]);
        int trackFinal=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=final[trackFinal][1]){
                vector <int> temp=final[trackFinal];
                final.pop_back();
                if(intervals[i][1]>=temp[1])
                final.push_back({temp[0],intervals[i][1]});
                else 
                final.push_back({temp[0],temp[1]});
            }else{
                final.push_back({intervals[i]}); 
                trackFinal++;
            }

        }
        return final;
    }
};