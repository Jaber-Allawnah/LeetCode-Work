class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> arrayMap;

        for(int i = 0; i < nums.size(); i++){
            arrayMap[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){

            int value = target - nums[i];

            if(arrayMap.count(value) && arrayMap[value] != i){
                return {i, arrayMap[value]};
            }
        }

        return {};
    }
};