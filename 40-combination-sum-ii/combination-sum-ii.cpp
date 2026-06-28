class Solution {
private:
vector<vector<int>>final;
int target;
vector<int> candidates;
public:
    int findSum(vector<int> current){
        int sum=0;
        for(int i=0;i<current.size();i++){
            sum+=current[i];
        }
        return sum;
    }
    void backTrack(vector<int> current,int i){
        if(findSum(current)==target){
            final.push_back(current);
            return;
        }else if(findSum(current)>target){
            return;
        }else{
            for(int j=i+1;j<candidates.size();j++){
                if(j>i+1&&candidates[j]==candidates[j-1]) continue;
                current.push_back(candidates[j]);
                backTrack(current,j);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> current;
        this->target=target;
        this->candidates=candidates;
        for(int i=0;i<candidates.size();i++){
            if(i>0&&candidates[i]==candidates[i-1]) continue;
            current.push_back(candidates[i]);
            backTrack(current,i);
            current.pop_back();
        }
        return final;
    }
};