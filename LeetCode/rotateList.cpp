// Problem: https://leetcode.com/problems/rotate-list/

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
    int findLength(ListNode *head){
        int len = 0 ;
        while(head != NULL){
            len++ ;
            head = head -> next ;
        }
        return len ;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL)
            return head ;
        
        ListNode *first = head, *second = head ;
        
        int len = findLength(head) ;
        k = k % len ;
        
        for(int i = 0 ; i < k ; i++)
            first = first -> next ;
        
        while(first -> next != NULL){
            first = first -> next ;
            second = second -> next ;
        }
        
        first -> next = head ;
        head = second -> next ;
        second -> next = NULL ;
        
        return head ;
            
    }
};