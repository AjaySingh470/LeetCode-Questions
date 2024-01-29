class MyQueue {
public:
    stack<int> q , temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int res = peek();
        temp.pop();
        return res;
    }
    
    int peek() {
        if(temp.empty())
        {
            
            while(!q.empty())
            {
                temp.push(q.top());
                q.pop();
            }
        }
        int tp = temp.top();
        return tp;
    }
    
    bool empty() {
        return q.empty() && temp.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */