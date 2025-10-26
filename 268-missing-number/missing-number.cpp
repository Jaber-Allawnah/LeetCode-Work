class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int acutalSum=0,expectedSum=0;
        for(int i=1;i<=nums.size();i++){
            expectedSum+=i;
        }
        for(int i=0;i<nums.size();i++){
            acutalSum+=nums[i];
        }
        return expectedSum-acutalSum;
    }
};