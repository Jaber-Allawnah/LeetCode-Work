class Solution {
private:
        vector<vector<int>> final;
public:
    void backTrack(int remaining,int start,vector<int> current,vector<int>& nums){
        if(remaining==0){
            final.push_back(current);
        }else{
            for(int i=start;i<nums.size();i++){
                if(find(current.begin(),current.end(),nums[i])!=current.end()) continue;
                current.push_back(nums[i]);
                backTrack(remaining-1,0,current,nums);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        backTrack(nums.size(),0,current,nums);
        return final;
    }
};