class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max=0;
        unordered_map<int,int> hashTable;
        for(int i=0;i<nums.size();i++){
            hashTable[nums[i]]=0;
        }
        for(int i=0,j=0;i<nums.size();i++){
            if(hashTable[nums[i]]>0)
            continue;
            j=1;
            if(!(hashTable.count(nums[i]-1))){
                hashTable[nums[i]]++;
                if(hashTable[nums[i]]>max)
                    max=hashTable[nums[i]];  
                while(hashTable.count(nums[i]+j)){
                        hashTable[nums[i]]++;
                        j++;
                        if(hashTable[nums[i]]>max)
                        max=hashTable[nums[i]];  
                }
            }
        }
        return max;
        
    }
};