class Solution {
    vector<vector<int>> final;
public:
    void backTrack(int start,int size,vector<int> mySet,vector<int> current ){
        if(current.size()==size){
            final.push_back(current);
            return;
        }
        for(int i=start;i<mySet.size();i++){
            current.push_back(mySet[i]);
            backTrack(i+1,size,mySet,current);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> mySet(n);
        for(int i=0;i<n;i++){
            mySet[i]=i+1;
        }
        vector<int> current;
        backTrack(0,k,mySet,current);
        return final;
    }
};