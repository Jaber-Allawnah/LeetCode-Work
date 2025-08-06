class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> myStack;
        int temp1;
        int temp2;
        if(tokens.empty())
            return 0;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="/"&&tokens[i]!="*")
            myStack.push(stoi(tokens[i]));

            else if(tokens[i]=="+"){
                temp1=myStack.top();
                myStack.pop();
                temp2=myStack.top();
                myStack.pop();
                myStack.push(temp1+temp2);
            }
            else if(tokens[i]=="-"){
                temp1=myStack.top();
                myStack.pop();
                temp2=myStack.top();
                myStack.pop();
                myStack.push(temp2-temp1);                
            }
            else if(tokens[i]=="*"){
                temp1=myStack.top();
                myStack.pop();
                temp2=myStack.top();
                myStack.pop();
                myStack.push(temp1*temp2);                
            }
            else if(tokens[i]=="/"){
                temp1=myStack.top();
                myStack.pop();
                temp2=myStack.top();
                myStack.pop();
                myStack.push(temp2/temp1);                
            }                                    
        }
        return myStack.top();
    }
};