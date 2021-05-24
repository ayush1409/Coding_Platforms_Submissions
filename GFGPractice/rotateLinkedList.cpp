// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    
    Node *findEnd(Node *head){
        if(head == NULL)
            return NULL ;
            
        while(head -> next != NULL)
            head = head -> next ;
        
        return head ;
    }
    
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        if(head == NULL || head -> next == NULL)
            return head ;
            
        Node *t = head ;
        
        for(int i = 0 ; i < k-1 ; i++){
            if(t != NULL)
                t = t -> next ;
        }
        
        if(t == NULL || t -> next == NULL)
            return head ;
        
        Node *newHead = t -> next ;
        t -> next = NULL ;
        
        Node *end = findEnd(newHead) ;
        if(end != NULL)
            end -> next = head ;

        return newHead ;
    }
};
    


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends