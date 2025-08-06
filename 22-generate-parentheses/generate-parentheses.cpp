class Solution {
public:
    vector<string> final;
    void backtrack(string current,int open,int close,int n){
        if(open+close==n*2){
        final.push_back(current);
        return;
        }
        
        if(open<n){
            backtrack(current+"(",open+1,close,n);
        }
        if(close<open){
            backtrack(current+")",open,close+1,n);
        }        

    }

    vector<string> generateParenthesis(int n) {
        backtrack("",0,0,n);
        return final;
    }
};
