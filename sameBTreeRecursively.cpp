/*
Check if SameTree - Theoritically A Unique Binary tree can be formed from Preorder and Inorder Traversal
We can check if the Preorder and Inorder traversal of both the tree are equal then they are same

But Interms of Solving it with code 

    Recursive Approach :
        Checking for the NULL case first :  both root are null they are same
                                            either of the root is null then Trees are not similar
                                            if root value of both the tree are not equal trees are not same

        Recursively checking for the left subtree of both and right subtree of both the tree.


        Time Complexity     - O(N) - N is the number of nodes
        Space Complexity    - O(N) Worst case - For Auxilary Stack used in recursion with Skew Tree 

*/

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL && q == NULL)
        return true;
    if(p==NULL || q == NULL)
        return false;
    if(p->val != q->val)
        return false;
    return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }