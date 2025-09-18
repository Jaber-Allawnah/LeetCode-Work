class Solution {
public:
    string helperfunction(int l,int r,string s){
        string final;
        while(l>=0&&r<=(s.size()-1)&&s[l]==s[r]){
            final=s.substr(l,r-l+1);
            l--;
            r++;
        }
        return final;
    }
    string longestPalindrome(string s) {
        string final ="";
        if(s.size()==1)
        return s;
        for(int i=0;i<s.size();i++){
            string s1=helperfunction(i,i,s);
            if(s1.size()>final.size()){
                final=s1;
            }
            string s2=helperfunction(i,i+1,s);
            if(s2.size()>final.size()){
                final=s2;
            }
        }

        return final;
    }
};