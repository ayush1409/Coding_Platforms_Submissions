// Problem: https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head ;
        
        if(head == NULL)
            return NULL ;
        
        do{
            fast = fast -> next ;
            if(fast == NULL)
                return NULL ;
            fast = fast -> next ;
            slow = slow -> next ;
        }while(slow != NULL && fast != NULL && slow != fast) ;
        
        if(fast == NULL)
            return NULL ;
        fast = head ;
        
        while(slow != fast){
            slow = slow -> next ;
            fast = fast -> next ;
        }
        
        return slow ;
    }
};