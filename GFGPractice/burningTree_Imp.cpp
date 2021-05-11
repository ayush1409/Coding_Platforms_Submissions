// Problem : https://practice.geeksforgeeks.org/problems/burning-tree/1#
/*
    Problem : Given a binary tree and a leaf node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is, its left child, right child and parent.

    Example 1:
    Input :      
            1
            /   \
        2      3
        /  \      \
    4    5      6
        / \      \
        7   8      9
                    \
                    10

    Target Node = 8
    Output: 7
    Explanation: If leaf with the value 
    8 is set on fire. 
    After 1 sec: 5 is set on fire.
    After 2 sec: 2, 7 are set to fire.
    After 3 sec: 4, 1 are set to fire.
    After 4 sec: 3 is set to fire.
    After 5 sec: 6 is set to fire.
    After 6 sec: 9 is set to fire.
    After 7 sec: 10 is set to fire.
    It takes 7s to burn the complete tree.
    
    Example 2:
    Input :      
            1
            /   \
        2      3
        /  \      \
    4    5      7
    /    / 
    8    10
    Target Node = 10
    Output: 5
    Your Task:  
    You dont need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(height of tree)

    Constraints:
    1 ≤ N ≤ 10^4
*/

class Solution {
    public:
    /*  
    ***********ADDITIONAL INFO*************
    lDepth - maximum height of left subtree
    rDepth - maximum height of right subtree
    contains - stores true if tree rooted at current node 
               contains the first burnt node
    time - time to reach fire from the initally burnt leaf 
           node to this node
*/
struct Info {
    int lDepth;
    int rDepth;
    bool contains;

    int time;

    Info()
    {
        lDepth = rDepth = 0;
        contains = false;

        time = -1;
    }
};

/*  
    Function to calculate time required to burn 
    tree completely
    
    node - address of current node
    info - extra information about current node
    target - node that is fired
    res - stores the result
*/
Info calcTime(Node* node, Info& info, int target, int& res)
{

    // Base case: if root is null
    if (node == NULL) {
        return info;
    }

    // If current node is leaf
    if (node->left == NULL && node->right == NULL) {

        // If current node is the first burnt node
        if (node->data == target) {
            info.contains = true;
            info.time = 0;
        }
        return info;
    }

    // Information about left child of root
    Info leftInfo;
    calcTime(node->left, leftInfo, target, res);

    // Information about right child of root
    Info rightInfo;
    calcTime(node->right, rightInfo, target, res);

    // If left subtree contains the fired node then
    // time required to reach fire to current node
    // will be (1 + time required for left child)
    info.time = (node->left && leftInfo.contains) ? (leftInfo.time + 1) : -1;

    // If right subtree contains the fired node then
    // time required to reach fire to current node
    // will be (1 + time required for right child)
    if (info.time == -1)
        info.time = (node->right && rightInfo.contains) ? (rightInfo.time + 1) : -1;

    // Storing(true or false) if the tree rooted at
    // current node contains the fired node
    info.contains = ((node->left && leftInfo.contains) || (node->right && rightInfo.contains));

    // Calculate the maximum depth of left subtree
    info.lDepth = !(node->left) ? 0 : (1 + max(leftInfo.lDepth, leftInfo.rDepth));

    // Calculate the maximum depth of right subtree
    info.rDepth = !(node->right) ? 0 : (1 + max(rightInfo.lDepth, rightInfo.rDepth));

    // Calculating answer
    if (info.contains) {
        // If left subtree exists and
        // it contains the fired node
        if (node->left && leftInfo.contains) {
            // calculate result
            res = max(res, info.time + info.rDepth);
        }

        // If right subtree exists and it
        // contains the fired node
        if (node->right && rightInfo.contains) {
            // calculate result
            res = max(res, info.time + info.lDepth);
        }
    }
}

    // Driver function to calculate minimum
    // time required
    int minTime(Node* root, int target)
    {
        int res = 0;
        Info info;

        calcTime(root, info, target, res);

        return res;
    }
};

/*
    COMPLETE EDITORIAL
    Given a binary tree and a leaf node from this tree. It is known that in 1s all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on. The task is to find the minimum time required to burn the complete binary tree.


    Examples:
    Input : 
                1
        /       \
        2          3
        /  \          \
    4    5          6
        /   \         \
        7     8         9
                        \
                        10
    Leaf = 8
    Output : 7
    Initially 8 is set to fire at 0th sec.
                1
        /       \
        2          3
        /  \          \
    4    5          6
        /   \         \
        7     F         9
                        \
                        10
    After 1s: 5 is set to fire.
                1
        /       \
        2          3
        /  \          \
    4    F          6
        /   \         \
        7     F         9
                        \
                        10
    After 2s: 2, 7 are set to fire.
                1
        /       \
        F          3
        /  \          \
    4    F          6
        /   \         \
        F     F         9
                        \
                        10
    After 3s: 4, 1 are set to fire.
                F
        /       \
        F          3
        /  \          \
    F    F          6
        /   \         \
        F     F         9
                        \
                        10
    After 4s: 3 is set to fire.
                F
        /       \
        F          F
        /  \          \
    F    F          6
        /   \         \
        F     F         9
                        \
                        10
    After 5s: 6 is set to fire.
                F
        /       \
        F          F
        /  \          \
    F    F          F
        /   \         \
        F     F         9
                        \
                        10
    After 6s: 9 is set to fire.
                F
        /       \
        F          F
        /  \          \
    F    F          F
        /   \         \
        F     F         F
                        \
                        10
    After 7s: 10 is set to fire.
                F
        /       \
        F          F
        /  \          \
    F    F          F
        /   \         \
        F     F         F
                        \
                        F
    It takes 7s to burn the complete tree.


    The idea is to store additional information for every node:
    Depth of left subtree.
    Depth of right subtree.
    The time required for the fire to reach the current node starting from the first leaf node burned.
    A boolean variable to check if the initial burnt node is in the tree rooted under current node.

    Before moving ahead with the approach let's take a look at the tree below:
                1
            /      \          
        2            3
        /   \         /
        4     5       6 
    /     / \
    8     9   10
        /
        11

    In the above tree, if we set the leaf node 11 at fire.

    In 1s, the fire will reach node 9.
    In 2s, the fire will reach node 5.
    In 3rd second, the fire will reach node 2 and 10. Here comes an observation:
    In 2s fire reached node 5. For node 5, the initial burned leaf is in it's left subtree, so the time taken to burn right subtree will be the height of the right subtree which is 1. Therefore, fire reaches to node 10 in (2+1) = 3s.
    Again, for the node 2. Fire reached to node 2 in 3s from right subtree. Therefore, time taken to burn left subtree will be it's height.

    So the solution is to apply recursion and for every node calculate the below-required values:
    Left Depth.
    Right Depth.
    The time required for fire to reach the current node.
    Is the current subtree conatins initial burnt leaf node.

    So, for the minimum time required to burn any subtree will be:
    The time required for fire to reach the root node from initial burnt leaf + depth of the opposite side

    Therefore, to find time required to burn the complete tree, we need to calculate the above value for every node, and take maximum of that value.
    ans = max(ans, (time required for fire to reach current node + depth of other subtree))
*/