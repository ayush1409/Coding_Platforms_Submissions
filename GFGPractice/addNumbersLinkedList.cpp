struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



class Solution
{
    public:
    
    Node* reverseList(struct Node *head){
        Node *prev = NULL ;
        Node *curr = head ;
        Node *nxt = head -> next ;
        
        while(curr != NULL){
            nxt = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = nxt ;
        }
        
        return prev ;
    }
    
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverseList(first) ;
        second = reverseList(second) ;
        
        if(first == NULL && second == NULL)
            return NULL ;
        
        int carry = 0 ;
        int a,b ;
        
        Node *result = NULL ;
        
        if(first != NULL){
            if(second != NULL){
                a = first -> data ;
                b = second -> data ;
                result = new Node((a + b + carry)%10) ;
                carry = (a+b)/10 ;
                first = first -> next ;
                second = second -> next ;
                
            }
            else{
                a = first -> data ;
                result = new Node(a) ;
                first = first -> next ;
                return result ;
            }
                    
        }
        else if(second != NULL){
                b = second -> data ;
                result = new Node(b) ;
                second = second -> next ;
                return result ;
        }
        
        Node *tempResult = result ;
    
        while(first != NULL && second != NULL){
            a = first -> data ;
            b = second -> data ;
            tempResult -> next = new Node((a + b + carry)%10) ;
            carry = (a + b + carry)/10 ;
        
            first = first -> next ;
            second = second -> next ;
            tempResult = tempResult -> next ;
        }
        
        while(first != NULL){
            tempResult -> next = new Node((first->data + carry)%10) ;
            carry = (carry + first -> data)/10;
            first = first -> next ;
            tempResult = tempResult -> next ;
        }
        
        while(second != NULL){
            tempResult -> next = new Node((second -> data + carry)%10) ;
            carry = (carry + second -> data)/10 ;
            second = second -> next ;
            tempResult = tempResult -> next ;
        }
        
        if(carry != 0){
            tempResult -> next = new Node(carry) ;
            tempResult = tempResult -> next ;
        }        
        tempResult -> next = NULL ;
        
        result = reverseList(result) ;
        
        return result ;
    }
};
