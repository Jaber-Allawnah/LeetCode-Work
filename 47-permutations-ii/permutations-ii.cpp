class Solution {
private:
vector<vector<int>> final;
public:
    void backTrack(vector<int>& nums,vector<int> current,vector<bool> used){
        if(current.size()==nums.size()){
            if(find(final.begin(),final.end(),current)!=final.end()) return;
            final.push_back(current);
            return;
        }else{
            for(int i=0;i<nums.size();i++){
                if(used[i]) continue;
                current.push_back(nums[i]);
                used[i]=true;
                backTrack(nums,current,used);
                current.pop_back();
                used[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> current;
        vector<bool> used(nums.size(),false);
        backTrack(nums,current,used);
        return final;
    }
};