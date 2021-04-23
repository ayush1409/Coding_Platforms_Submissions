// Problem : https://leetcode.com/problems/min-stack/

class MinStack {
public:
    
    /** initialize your data structure here. */
    stack<int> s ;
    stack<int> minStack ;
    
    MinStack() {
        
    }
    
    void push(int val) {
        this->s.push(val) ;
        
        if(this->minStack.empty())
            this->minStack.push(val) ;
        
        else if(this ->minStack.top() >= val)
            this->minStack.push(val) ;
    }
    
    void pop() {
        if(s.empty())
            return ;
        
        int x = this -> s.top();
        s.pop();
        
        if(x == this->minStack.top())
            this->minStack.pop() ;
    }
    
    int top() {
        return this->s.top() ;
    }
    
    int getMin() {
        return this -> minStack.top() ;
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