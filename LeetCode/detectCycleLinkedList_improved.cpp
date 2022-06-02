/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head ;
        
        if(head == NULL || head -> next == NULL)
            return false ;
        
        while(fast != NULL){
            fast = fast -> next ;
            
            if(fast == NULL)
                return false ;
            
            fast = fast -> next ;
            slow = slow -> next ;
            
            if(fast == slow)
                return true ;
        }
        
        return false ;
    }
};

/*

fast = head, slow = head

while fast != NULL:
    fast = fast -> next
    if fast == NULL:
        return False
    fast = fast -> next
    slow = slow -> next
    
    if fast == slow:
        return true

*/
