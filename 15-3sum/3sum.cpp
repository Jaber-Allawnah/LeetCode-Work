class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> final;
        sort(nums.begin(),nums.end());
        int size=nums.size();
        for(int i=0;i<size-2;i++){
            int k=size-1;
            int j=i+1;
            if(i>0&&(nums[i]==nums[i-1])) continue;
            while(j<k){

                if(nums[j]+nums[k]+nums[i]==0){
                    final.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k&&nums[k+1]==nums[k]) k--;
                    while(j<k&&nums[j-1]==nums[j]) j++;
                }
                else if(nums[j]+nums[k]+nums[i]<0){
                    j++;
                }
                else if(nums[j]+nums[k]+nums[i]>0){
                    k--;
                }
            }
        }
        return final;
    }
};