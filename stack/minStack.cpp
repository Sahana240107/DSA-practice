/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

*/
class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        mini=LLONG_MAX;
    }
    
    void push(int val) {
        long long v=val;
        if(st.empty())
        {
            st.push(v);
            mini=v;
        }
        else
        {
            if(v<mini)
            {
                st.push(2LL*v-mini);
                mini=v;
            }
            else
                st.push(v);
        }
    }
    
    void pop() {
        if(!st.empty())
        {
            long long top=st.top();
            st.pop();
            if(top<mini)
            {
                mini=2LL*mini-top;
            }
        }
    }
    
    int top() {
        if(st.empty())
            return -1;
        long long top=st.top();
        if(top<mini)
            return (int)mini;
        return (int)top;
    }
    
    int getMin() {
        return (int)mini;
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