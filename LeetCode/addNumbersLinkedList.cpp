// Problem : https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL && l2 == NULL)
            return NULL ;
        
        int carry = 0 , a , b ;
        
        ListNode *result = NULL ;
        
        
        // Adding first result node
        if(l1 != NULL){
            if(l2 != NULL){
                a = l1 -> val ;
                b = l2 -> val ;
                result = new ListNode((a + b + carry)%10) ;
                carry = (a + b)/10 ;
                l1 = l1 -> next ;
                l2 = l2 -> next ;
            }
            else 
                return l1 ;
        }
        else
            return l2 ;
        
        ListNode *resultTemp = result;
        
        while(l1 != NULL && l2 != NULL){
            a = l1 -> val ;
            b = l2 -> val ;
            resultTemp -> next = new ListNode((a+b+carry)%10) ;
            carry = (a + b + carry)/10 ;
            l1 = l1 -> next ;
            l2 = l2 -> next ;
            resultTemp = resultTemp -> next ;
        }
        
        while(l1 != NULL){
            a = l1 -> val ;
            resultTemp -> next = new ListNode((a+carry)%10) ;
            carry = (a + carry)/10 ;
            l1 = l1 -> next ;
            resultTemp = resultTemp -> next ;
        }
        
        while(l2 != NULL){
            b = l2 -> val ;
            resultTemp -> next = new ListNode((b+carry)%10) ;
            carry = (b + carry)/10 ;
            l2 = l2 -> next ;
            resultTemp = resultTemp -> next ;
        }
        
        if(carry != 0){
            resultTemp -> next = new ListNode(carry) ;
            resultTemp = resultTemp -> next ;
        }
        
        resultTemp -> next = NULL ;
        
        return result ;
    }
};