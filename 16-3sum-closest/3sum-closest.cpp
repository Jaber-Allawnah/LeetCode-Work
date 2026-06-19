class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sumFinal=0;
        sort(nums.begin(),nums.end());
        int size=nums.size();
        int currentSum=0;
        int sumClosest=nums[0]+nums[1]+nums[size-1];
        for(int i=0;i<size-2;i++){
            int j=i+1;
            int k=size-1;
            while(j<k){
                currentSum=nums[i]+nums[j]+nums[k];
                if(currentSum<target){
                    j++;
                }else if(currentSum>target){
                    k--;
                }else if(currentSum==target)return currentSum;
                if(abs(currentSum-target)<abs(sumClosest-target)){
                    sumClosest=currentSum;
                }
            }
        }
        sumFinal=sumClosest;
        return sumFinal;
    }
};