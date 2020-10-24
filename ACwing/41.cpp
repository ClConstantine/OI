class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> val,min; 

    MinStack() {

    }
    
    void push(int x) {
        if(val.empty() || x < min.top()){
        	min.push(x);
        }
        else min.push(min.top());
        val.push(x);
        return ;
    }
    
    void pop() {
        val.pop();
        min.pop();
        return ;
    }
    
    int top() {
        return val.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */