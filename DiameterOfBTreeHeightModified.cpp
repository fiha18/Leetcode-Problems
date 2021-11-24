

// Changing values of 
int findMax(TreeNode* root,int& diameter)
    {
        if(root==NULL)return 0;
        
        int lh = findMax(root->left,diameter);
        int rh = findMax(root->right,diameter);
        
        diameter = max(diameter,(lh+rh));
        
        return 1+ max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int res = findMax(root,diameter);
        return diameter;
}