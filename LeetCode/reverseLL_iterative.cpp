// Problem: https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        // iterative
        
        if(!head || !(head -> next))
            return head ;
        
        ListNode *prev = NULL, *curr = head, *nxt = NULL ;
        
        while(curr != NULL){
            nxt = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = nxt ;
        }
        
        return prev ;
        
    }
};