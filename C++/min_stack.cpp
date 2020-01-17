class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    int min;
    
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        stack.push_back(x);
        if(x < min) min = x; 
    }
    
    void pop() {
        if(top() == min) {
            if(stack.size() == 1) {
                min = INT_MAX;
            } else {
                min = stack[0];
            }
            for(int i = 0; i < stack.size() - 1; ++i) {
                if (stack[i] < min) min = stack[i];
            }
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
