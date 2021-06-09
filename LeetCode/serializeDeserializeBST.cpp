// Problem: https://leetcode.com/problems/serialize-and-deserialize-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    string getPreorder(TreeNode *root){
        if(root == NULL)
            return "" ;
        
        if(root -> left == NULL && root -> right == NULL)
            return to_string(root -> val) ;
        
        string leftPreorder = getPreorder(root -> left) ;
        string rightPreorder = getPreorder(root -> right) ;
        
        string s = to_string(root -> val) ;
        if(!leftPreorder.empty())
            s = s + " " + leftPreorder ;
        if(!rightPreorder.empty())
            s = s + " " + rightPreorder ;
        
        return s ;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string preorder = getPreorder(root) ;
        return preorder ;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int i, int j, int &k){
        if(i > j)
            return NULL ;
        
        if(i == j && preorder[k] == inorder[i])
            return new TreeNode(preorder[k++]) ;
        
        int mid ;
        for(mid = i ; mid < inorder.size() ; mid++)
            if(preorder[k] == inorder[mid])
                break ;

        TreeNode *root = new TreeNode(preorder[k]) ;
        k++ ;
        root -> left = buildTree(preorder, inorder, i, mid-1, k) ;
        root -> right = buildTree(preorder, inorder, mid+1, j, k) ;
        
        return root ;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preorder ;
        int j ;
        string val ;
        
        for(int i = 0 ; i < data.size() ;){
            j = i+1 ;
            
            while(j < data.size() && data[j] != ' ')
                j++ ;
        
            val = data.substr(i, j-i) ; 
            //cout<<val<<endl ;
            preorder.push_back(stoi(val)) ;
            i = j + 1 ;
        }
        
        vector<int> inorder(preorder.begin(), preorder.end()) ;
        sort(inorder.begin(), inorder.end()) ;
        
        int k = 0 ;
        return buildTree(preorder, inorder, 0, inorder.size()-1, k) ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;