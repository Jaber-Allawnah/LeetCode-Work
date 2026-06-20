class Solution {
public:
    int search(vector<int>& nums, int target) {
        bool found=false;
        int i;
        for(i=0;i<nums.size();i++){
            if(nums[i]==target){
                found=true;
                break;
            }
        }
        return found?i:-1;
    }
};