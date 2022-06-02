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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == headB)
            return headA ;
        
        ListNode *dummyA = headA, *dummyB = headB ;
        
        while(dummyA != dummyB){
            dummyA = dummyA -> next ;
            dummyB = dummyB -> next ;
            
            if(dummyA == NULL && dummyB == NULL)
                return NULL ;
            
            if(dummyA == NULL)
                dummyA = headB ;
            if(dummyB == NULL)
                dummyB = headA ;
        }
        
        return dummyA ;
    }
};

/*

dumA = headA, dumB = headB

while dummA != dummB:
    dummA = dummA -> next
    dummB = dummB -> next
    
    if dummA == NULL and dummB == NULL:
        return NULL
    
    if dummA == NULL:
        dummA = headB
    if dummB == NULL:
        dummB = headA
return dummyA
    
*/
