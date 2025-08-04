class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int temp;
        bool isGreatest;
        vector<bool> output(candies.size(),false);
        for(int i=0;i<candies.size();i++){
            temp=candies[i]+extraCandies;
            isGreatest=true;
            for(int j=0;j<candies.size()&&isGreatest;j++){
                if(temp<candies[j]){
                isGreatest=false;
                }
            }
            output[i]=isGreatest;

        }
        return output;
    }
};