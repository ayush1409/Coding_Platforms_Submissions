// Problem: https://leetcode.com/problems/reverse-linked-list-ii/description/
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
    ListNode* reverseLinkedList(ListNode *start, ListNode *end){
        ListNode *prev = NULL, *curr = start, *nxt = NULL ;
        while(curr != NULL && prev != end){
            nxt = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = nxt ;
        }
        ListNode *temp = prev ;
        // while(prev != NULL){
        //     cout<<prev -> val << " " ;
        //     prev = prev -> next ;
        // }
        return prev ;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head -> next == NULL || left == right) return head ;
        ListNode *leftPtr = head, *rightPtr = head, *leftTmp = NULL, *rightTmp = NULL ;
        for(int i = 1 ; i < left ; i++){
            leftTmp = leftPtr ;
            leftPtr = leftPtr -> next ;
        }
        rightPtr = leftPtr ;
        for(int i = 1 ; i <= right - left ; i++){
            rightPtr = rightPtr -> next ;
            rightTmp = rightPtr == NULL ? NULL : rightPtr -> next ;
        }

        ListNode *temp = NULL ;
        if(leftTmp == NULL){
            head = reverseLinkedList(leftPtr, rightPtr) ;
            temp = head ;
        }
        else{
            leftTmp -> next = reverseLinkedList(leftPtr, rightPtr) ;
            temp = leftTmp -> next ;
        }    
    
        if(leftPtr) leftPtr -> next = rightTmp ;
        return head ;
    }
};