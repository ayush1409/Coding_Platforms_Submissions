// Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head, *second = head ;
        
        if(head -> next == NULL)
            return NULL ;
        
        // get length of ListNode
        int length = 0 ;
        ListNode *temp = head ;
        while(temp != NULL){
            length++ ;
            temp = temp -> next ;
        }
        
        // delete the first node when length is equal to n
        if(length == n)
            return head->next ;
        
        
        
        for(int i = 0 ; i < n ; i++){
            first = first -> next ;
        }
        
        while(first -> next != NULL){
            first = first -> next ;
            second = second -> next ;
        }
        
        temp = second -> next ;
        second -> next = second -> next -> next ;
        delete temp ;
        
        return head;
    }
};