class Solution {
private:
unordered_map<char, vector<char>> myMap = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}
};
public:
    void myRecFunc(vector<string>&final,string digits,string current,int i){
        if(current.length()==digits.length()){
            final.push_back(current);
            return;
        }
        for(char c:myMap[digits[i]]){
            current.push_back(c);
            myRecFunc(final,digits,current,i+1);
            current.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> final;
        string current="";
        int i=0;
        myRecFunc(final,digits,current,i);
        return final;
    
    }
};