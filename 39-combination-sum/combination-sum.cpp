class Solution {
private:
    vector<vector<int>> final;
public:
    int findSum(vector<int> current){
        int sum=0;
        for(int i=0;i<current.size();i++){
            sum+=current[i];
        }
        return sum;
    }

    void backTrack(vector<int>& candidates, int target,vector<int> current,int number){
        if(findSum(current)==target){
            final.push_back(current);
            return;
        }else if(findSum(current)>target){
            return;
        }
        else{
        for(int num:candidates){
            if(number>num) continue;
            current.push_back(num);
            backTrack(candidates,target,current,num);
            current.pop_back();
        }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        for(int num:candidates){
            current.push_back(num);
            backTrack(candidates,target,current,num);
            current.pop_back();
        }
        return final; 
    }
};