class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int i;
        sort(nums.begin(),nums.end());//asc
        for(i=0;i<n;i++){
            if(i==nums[i])
            continue;
            else return i;
        }
        
    return i;
    }
};