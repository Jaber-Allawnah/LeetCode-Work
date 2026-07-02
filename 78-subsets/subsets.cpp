class Solution {
private:
vector<vector<int>> final;
public:
    void backTrack(int start,vector<int> current,vector<int>& nums){
        if(current.size()<=nums.size()){
            final.push_back(current);
            if(current.size()==nums.size()){
                return;
            }
        }
        for(int i=start;i<nums.size();i++){
            current.push_back(nums[i]);
            backTrack(i+1,current,nums);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backTrack(0,current,nums);
        return final;
    }
};