class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        s.push(x);
        if(minx.empty() || x <= minx.top()){
            minx.push(x);
        }
    }
    
    void pop() {
        if(!s.empty()){
            int t = s.top();
            s.pop();
            if(t == minx.top()){
                minx.pop();
            }
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minx.top();
    }

private:
    stack<int> s;
    stack<int> minx;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */