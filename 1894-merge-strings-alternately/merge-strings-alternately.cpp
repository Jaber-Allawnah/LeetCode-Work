class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int x=word1.size();
        int y=word2.size();
        string final="";
        for(int i=0,j=0;i<x||j<y;i++,j++){
            if(i<x){
            final+=word1[i];
            }
            if(j<y){
            final+=word2[j];
            }
        }
        return final;
    }
};