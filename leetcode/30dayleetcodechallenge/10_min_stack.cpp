class MinStack {
private:
    stack<pair<int, int>> min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(min_stack.empty())
            min_stack.push(make_pair(x, x));
        else{
            int min_value = min(x, min_stack.top().second);
            min_stack.push(make_pair(x, min_value));
        }
    }
    
    void pop() {
        min_stack.pop();
    }
    
    int top() {
        return min_stack.top().first;
    }
    
    int getMin() {
        return min_stack.top().second;
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