class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        if(flag){
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop(); 
            }
            flag = 0;
        }
        s1.push(value);
    }
    
    int deleteHead() {
        if(!flag){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            flag = 1;
        }
        if(s2.empty()) return -1;
        int res = s2.top();
        s2.pop();
        return res;
    }

private:
    stack<int> s1;
    stack<int> s2;
    int flag = 0;
};


//优化
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
        size++;
    }
    
    int deleteHead() {
        if(size == 0) return -1;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        size--;
        return res;
    }

private:
    stack<int> s1;
    stack<int> s2;
    int size = 0;
};
