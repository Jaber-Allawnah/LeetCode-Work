class Solution {
public:
    int findIndex(vector<int>& nums,int left,int right, int target){
        if (left > right) return left;
        int mid=left+(right-left)/2;
        if(target==nums[mid]) return mid;
        else if(target>nums[mid]){
            return findIndex(nums,mid+1,right,target);
        }
            return findIndex(nums,left,mid-1,target);
        
    }
    int searchInsert(vector<int>& nums, int target) {
        return findIndex(nums,0,nums.size()-1,target);
    }
};