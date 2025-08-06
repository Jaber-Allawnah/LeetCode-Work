class MinStack {
public:
        stack<int> myStack;
        stack<int> minStack;
    MinStack() {
        
        
    }
    
    void push(int val) {
        if(minStack.empty()||minStack.top()>=val)
            minStack.push(val);
        myStack.push(val);

    }
    
    void pop() {
        if(myStack.top()==minStack.top()){
            myStack.pop();
            minStack.pop();
        }
        else{
            myStack.pop();

        }
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */