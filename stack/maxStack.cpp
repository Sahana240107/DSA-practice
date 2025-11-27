/*Implement a class SpecialStack that supports following operations:

push(x) – Insert an integer x onto the stack.
pop() – Remove the top element from the stack.
peek() – Return the top element from the stack. If the stack is empty, return -1.
getMax() – Retrieve the maximum element from the stack in O(1) time. If the stack is empty, return -1.
isEmpty() –  Return true if stack is empty, else false
There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : Call push(x)
2:  Call pop()
3: Call peek()
4: Call getMax()
5: Call isEmpty()
The driver code will process the queries, call the corresponding functions, and print the outputs of peek(), getMax(), isEmpty() operations.
You only need to implement the above five functions.

Examples:

Input: q = 7, queries[][] = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]
Output: [3, 2, 2]
Explanation: Queries on stack are as follows:
push(2) into the Stack
push(3) into the Stack
return top of the stack, i.e 3
remove the element 3 from the top of the stack
return maximum element from the stack i.e 2
push(1) into the stack
return maximum element from the stack i.e 2*/
class SpecialStack {
  public:
    stack<long long> st;
    long long maxi;
    SpecialStack() {
        // Define Stack
        maxi=-1;
    }

    void push(int x) {
        // Push an element into the stack
        if(st.empty())
        {
            st.push(x);
            maxi=x;
        }
        else
        {
            if(maxi<x)
            {
                st.push(2LL*x-maxi);
                maxi=x;
            }
            else
                st.push(x);
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if(st.empty())
            return;
        long long top=st.top();
        st.pop();
        if(top>maxi)
        {
            maxi=2LL*maxi-top;
        }
        if(st.empty())//edge case
            maxi=-1;
    }

    int peek() {
        // Returns the top element
        if(st.empty())
            return -1;
        long long top=st.top();
        if(top>maxi)
        {
            top=maxi;
        }
        return (int)top;
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }

    int getMax() {
        // Return maximum element of Stack
        return maxi;
    }
};