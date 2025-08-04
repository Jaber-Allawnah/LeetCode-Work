class Solution {
public:
    int jump(vector<int>& nums) {
        int goal=nums.size()-1; 
        int count=0;
        int min=INT_MAX;

        if(nums.size()==1)
        return 0;
        
        while(1){
            for(int i=goal-1;i>=0;i--){
                if(i+nums[i]>=goal&&i<=min){
                    min=i;
                }

            }
            goal=min;
            count++;
            int min=INT_MAX;
            if(goal==0)
            break;
        }
        return count;
    }
};