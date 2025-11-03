class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(),nums.end());
        int j,k,n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])
            continue;
            if(nums[i]>0)
            break;
            j=i+1;
            k=n-1;
        while(j<k){ 
            long sum=nums[i]+nums[j]+nums[k];
            if(sum==0){
                triplets.push_back({nums[i],nums[j],nums[k]});
                int lv=nums[j],rv=nums[k];
                while(j<k&&nums[j]==lv) j++;
                while(j<k&&nums[k]==rv) k--;
            }else if (sum>0)
            k--;
            else if(sum<0)
            j++;

        }
    }
    return triplets;
    }
};