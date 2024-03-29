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
        // recursive
        if(head == NULL || head -> next == NULL)
            return head ;
        ListNode *nxt = head -> next ;
        ListNode *newHead = reverseList(head -> next) ;
        
        nxt -> next = head ;
        head -> next = NULL ;
        return newHead ;
    }
};