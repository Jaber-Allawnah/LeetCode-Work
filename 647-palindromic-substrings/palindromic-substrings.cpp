class Solution {
public:
    int count=0;
    void checkPal(int i,int j, string s){
        while(j< s.size()&&i>-1&&s[i]==s[j]){
            i--;
            j++;
            count++;
        }

    }
    int countSubstrings(string s) {
        for(int i=0;i<s.size();i++){
            checkPal(i,i,s);
            checkPal(i,i+1,s);
        }
        return count;
    }
};