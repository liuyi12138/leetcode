class CustomStack {
public:
    CustomStack(int maxSize) {
        maxs = maxSize;
    }
    
    void push(int x) {
        if(size < maxs){
            q.push_front(x);
            size++;
        }
    }
    
    int pop() {
        if(!q.empty()){
            int t = q.front();
            q.pop_front();
            size--;
            return t;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        while(!q.empty() && k > 0){
            temp.push(q.back() + val);
            q.pop_back();
            k--;
        }
        while(!temp.empty()){
            q.push_back(temp.top());
            temp.pop();
        }
    }
private:
    deque<int> q;
    int maxs = 0;
    int size = 0;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */