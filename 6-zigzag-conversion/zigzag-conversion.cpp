class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1||s.length() <= numRows) return s;
        vector <string> rows(numRows);
        bool isGoingDown=true;
        string result="";
        int row=0;
        for(int i=0;i<s.length();i++){
            if(isGoingDown){
                rows[row]+=s[i];
                if(!(row==numRows-1)){
                row++;
                continue;                    
                }                


                if(row==numRows-1){
                    isGoingDown=false;
                    row--;
                }
            }
            else if(!isGoingDown){
                rows[row]+=s[i];
                if(row!=0){
                    row--;
                    continue; 
                }                
                   
                
                if(row==0){
                    isGoingDown=true;
                    row++;
                }
            }
        }

        for(int i=0;i<numRows;i++){
            result+=rows[i];
        }
    return result;
    }
};  