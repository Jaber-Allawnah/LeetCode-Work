class Solution {
private:
vector<vector<int>>final;
vector<int> candidates;
public:
    void backTrack(int start,int remaining,vector<int> current){
        if(remaining==0){
            final.push_back(current);
        }
        for(int i=start;i<candidates.size();i++){
            if(i>start&&candidates[i]==candidates[i-1]) continue;
            if(remaining-candidates[i]<0) break;
            current.push_back(candidates[i]);
            backTrack(i+1,remaining - candidates[i],current);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> current;
        this->candidates=candidates;

        backTrack(0,target,{});
        
        return final;
    }
};