class MinStack {
    stack <int> st;
    stack <int> mst;
public:
    void push(int x) {
        if (mst.empty() || x <= mst.top())
            mst.push(x);
        st.push(x);
    }
    
    void pop() {
        if (st.empty())
            return;
        
        int x = st.top();
        if (!mst.empty() && x == mst.top())
            mst.pop();
        
        st.pop();
    }
    
    int top() {
        if (st.empty())
            return -1;

        return st.top();
    }
    
    int getMin() {
        if (mst.empty())
            return -1;

        return mst.top();
    }
};