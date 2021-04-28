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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int emptyListCount = 0 ;
        ListNode *result = NULL ;
        
        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i] == NULL)
                emptyListCount++ ;
        }
        
        if(emptyListCount == lists.size())
            return result ;
        
        priority_queue<int, vector<int>, greater<int> > pq ;
        
        for(int i = 0 ; i < lists.size() ; i++){
            ListNode *temp = lists[i] ;
            while(temp != NULL){
                pq.push(temp -> val) ;
                temp = temp -> next ;
            }
                
        }
        
        result = new ListNode(pq.top()) ;
        pq.pop() ;
        
        ListNode *resultTemp = result ;
        
        while(!pq.empty()){
            resultTemp -> next = new ListNode(pq.top()) ;
            pq.pop() ;
            resultTemp = resultTemp -> next ;
        }
        
        resultTemp -> next = NULL ;
        
        return result ;
    }
};