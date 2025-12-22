class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> myMap;
        for(int i=0;i<nums.size();i++){
            int compliment=target-nums[i];
            if(myMap.count(compliment))
            return {i,myMap[compliment]};
            myMap[nums[i]]=i;
        }
        return {};
    }

};