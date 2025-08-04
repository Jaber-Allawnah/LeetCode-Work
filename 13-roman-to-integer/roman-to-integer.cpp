class Solution {
public:
    int romanToInt(string s) {
        string romanArray="IVXLCDM";
        int resault=0;
        int intArray[]={1,5,10,50,100,500,1000};
        int current;
        int next;
        for(int i=0;i<s.length();i++){
            current=0;
            next=0;
            for(int j=0;j<romanArray.length();j++){
                    if(s[i]==romanArray[j]){
                        current=intArray[j];
                        break;
            } }

            if (i + 1 < s.length()) {            
            for(int j=0;j<romanArray.length();j++){
                for (int j = 0; j < romanArray.length(); j++) {
                    if (s[i + 1] == romanArray[j]) {
                        next = intArray[j];
                        break;
            }
            }
            }
            }
            if(current>=next)
                resault+=current;
            
            else if(current<next)
                resault-=current;
            
        }
        return resault;
    }
};