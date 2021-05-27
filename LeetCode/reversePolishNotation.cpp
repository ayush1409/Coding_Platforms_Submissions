// Problem: https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    bool isOperand(string ch){
        if(ch == "+" || ch == "-" || ch == "*" || ch == "/")
            return false ;
        return true ;
    }
    
    int compute(string op, int op1, int op2){
        if(op == "+")
            return op2 + op1 ;
        if(op == "-")
            return op2 - op1 ;
        if(op == "*")
            return op2 * op1 ;
        if(op == "/")
            return op2 / op1 ;
        return -1 ;
    }
    
    int evalRPN(vector<string>& tokens) {
        
        stack<int> operandStack ;
        
        for(int i = 0 ; i < tokens.size() ; i++){
            
            if(isOperand(tokens[i]))
                operandStack.push(stoi(tokens[i])) ;
            
            else{
                int op1 = operandStack.top() ;
                operandStack.pop() ;
                int op2 = operandStack.top() ;
                operandStack.pop() ;
                
                int result = compute(tokens[i], op1, op2) ;
                operandStack.push(result) ;
            }
        }
        
        return operandStack.top();
    }
};