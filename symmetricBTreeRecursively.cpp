/*
Checking if a binary tree is symmetric or not.

Recursive Approach:

Creating a recursive function isMirror that will recursively check if values are equal in mirror view.
    
    let root-leftsubtree = p and root-rightsubtree = q
    Now left-subtree of p = right-subtree of q and right-subtree of q = left-subtree of q
    if above true then its symmetric

*/

 bool isMirror(TreeNode* p,TreeNode* q)
    {
        if(p==NULL || q==NULL)
            return p==q;
        if(p->val != q->val)
            return false;
        return(isMirror(p->left,q->right) && isMirror(p->right,q->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isMirror(root->left,root->right);
    }