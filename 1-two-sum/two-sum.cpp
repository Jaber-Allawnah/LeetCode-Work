class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> arrayMap;
        vector<int> final;
        for(int i=0;i<nums.size();i++){
            arrayMap[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int value=target-nums[i];
            if(arrayMap.count(value)){
                if(i!=arrayMap[value])
                return {i,arrayMap[value]};
                continue;
            }        
        }

        return final;

    }
};