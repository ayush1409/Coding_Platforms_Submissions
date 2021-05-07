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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unsigned int getSize(ListNode *head){
        unsigned int n = 0 ;
        while(head != NULL){
            n++ ;
            head = head -> next ;
        }
        return n ;
    }
    
    TreeNode *listToBst(vector<int> &arr, int i, int j){
        if(i > j)
            return NULL ;
        
        int m = (j-i)/2 + i ;
        
        TreeNode *root = new TreeNode(arr[m]) ;
        root -> left = listToBst(arr, i, m-1) ;
        root -> right = listToBst(arr, m+1, j) ;
        
        return root ;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL ;
        
        unsigned int n = getSize(head) ; 
        vector<int> arr(n) ;
        ListNode *temp = head ;
        
        for(int i = 0 ; i < n ; i++){
            arr[i] = temp -> val ;
            temp = temp -> next ;
        }
        
        return listToBst(arr,0,n-1) ;
    }
};