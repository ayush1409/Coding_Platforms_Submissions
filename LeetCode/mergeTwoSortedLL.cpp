// Problem: https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Inplace merge, using prev, l1, l2 pointers
        if(list1 == NULL)
            return list2 ;
        
        if(list2 == NULL)
            return list1 ;
        
        ListNode *dummy = new ListNode(-1) ;
        ListNode *prev = dummy ;
        
        if(list1->val <= list2->val)
            dummy -> next = list1 ;
        else
            dummy -> next = list2 ;
        
        ListNode *l1 = list1, *l2 = list2 ;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                prev -> next = l1 ;
                l1 = l1 -> next ;
            }
            else{
                prev -> next = l2 ;
                l2 = l2 -> next ;
            }
            prev = prev -> next ;
        }
        
        if(l1 == NULL && l2 != NULL)
            prev -> next = l2 ;
        else if(l1 != NULL && l2 == NULL)
            prev -> next = l1 ;
        else
            prev -> next = NULL ;
        
        return dummy -> next ;
    }
};