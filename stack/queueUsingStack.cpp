class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s1.empty() || !s2.empty())
        {
            if(s2.empty())
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int val=s2.top();
            s2.pop();
            return val;
        }
        return -1;
    }
    
    int peek() {
        if(!s1.empty() || !s2.empty())
        {
            if(s2.empty())
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            return s2.top();
        }
        return -1;
    }
    
    bool empty() {
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }
};
