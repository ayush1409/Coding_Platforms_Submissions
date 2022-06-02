// Problem: https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddle(ListNode *head){
        ListNode *slow = head, *fast = head ;
        while(fast != NULL && fast -> next != NULL && fast -> next -> next != NULL){
            fast = fast -> next -> next ;
            slow = slow -> next ;
        }
        
        return slow ;
    }
    
    ListNode* reverse(ListNode *head){
        ListNode *prev = NULL, *curr = head, *nxt = NULL ;
        
        while(curr != NULL){
            nxt = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = nxt ;
        }
        
        return prev ;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL)
            return true ;
        
        ListNode *mid = findMiddle(head) ;
        ListNode *l2 = reverse(mid -> next) ;
        mid -> next = l2 ;
        ListNode *l1 = head ;
        
        while(l1 != NULL && l2 != NULL && l1->val == l2 -> val){
            l1 = l1 -> next ;
            l2 = l2 -> next ;
        }
        
        if(l2 == NULL)
            return true ;
        return false ;
    }
};


/*
// pseudo code
isPalindrome(head):
    mid = findMiddle()
    l2 = reverse(mid -> next)
    l1 = head
    
    while(l1 != NULL && l2 != NULL && l1->val == l2->val):
        l1 = l1 -> next
        l2 = l2 -> next
    
    if l2 == NULL:
        return true
    return false
 */       
