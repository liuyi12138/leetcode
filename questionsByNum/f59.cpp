class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(q.empty()) return -1;
        return max.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while(!max.empty() && value > max.back())
            max.pop_back();
        max.push_back(value);
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        int temp = q.front();
        q.pop();
        if(!max.empty() && max.front() == temp)
            max.pop_front();
        return temp;
    }

private:
    queue<int> q;
    deque<int> max;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */