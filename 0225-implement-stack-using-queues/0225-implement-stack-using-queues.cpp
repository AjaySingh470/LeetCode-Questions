class MyStack {
public:
    queue<int> q,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
         int x;
        for(int i=0;i<q.size()-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
        x = q.front();
        q.pop();
        return x;
       
    }
    
    int top() {
        int r;
        for(int i=0;i<q.size();i++)
        {
            r = q.front();
            q.push(q.front());
            q.pop();
        }
        return r;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */