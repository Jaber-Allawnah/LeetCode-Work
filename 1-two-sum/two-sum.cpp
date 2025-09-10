class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> final=nums;
        vector <int> answer;
        sort(final.begin(),final.end());
        int i=0;
        int j=nums.size()-1;
        while(1){
            if(final[i]+final[j]==target){
                break;
            }
            else if(final[i]+final[j]>target){
                j--;
            }
            else {
                i++;
            }

        }
        for(int k=0;k<nums.size();k++){
            if(nums[k]==final[i]||nums[k]==final[j]){
                answer.push_back(k);
            }
        }
        return answer;
    }
};