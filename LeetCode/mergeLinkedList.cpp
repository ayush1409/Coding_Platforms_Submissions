// Problem : https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL ;
        
        if(l1 == NULL)
            return l2 ;
        
        if(l2 == NULL)
            return l1 ;
        
        ListNode *result = NULL ;
        
        if(l1 -> val < l2 -> val){
            result = new ListNode(l1 -> val) ;
            l1 = l1 -> next ;
        }
        else{
            result = new ListNode(l2 -> val) ;
            l2 = l2 -> next ;
        }
        
        ListNode *resultTemp = result ;
        
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val < l2 -> val){
                resultTemp -> next = new ListNode(l1 -> val) ;
                l1 = l1 -> next ;
                resultTemp = resultTemp -> next ;
            }   
            else{
                resultTemp -> next = new ListNode(l2 -> val) ;
                l2 = l2 -> next ;
                resultTemp = resultTemp -> next ;
            }
        }
        
        while(l1 != NULL){
            resultTemp -> next = new ListNode(l1 -> val) ;
            l1 = l1 -> next ;
            resultTemp = resultTemp -> next ;
        }
        
        while(l2 != NULL){
            resultTemp -> next = new ListNode(l2 -> val) ;
            l2 = l2 -> next ;
            resultTemp = resultTemp -> next ;
        }
        
        resultTemp -> next = NULL ;
        
        return result ;
         
    }
};