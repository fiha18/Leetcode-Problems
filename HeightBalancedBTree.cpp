 int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lH = height(root->left);
        int rH = height(root->right);
        
        if((lH-rH)!=-1 && (lH-rH)!=0 && (lH-rH)!=1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }