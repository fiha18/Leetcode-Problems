 int findMax(TreeNode* root,int& maxi)
    {
        if(root==NULL)return 0;
        
        int lh = findMax(root->left,maxi);
        int rh = findMax(root->right,maxi);
        
        maxi = max(maxi,(lh+rh));
        
        return 1+ max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        int res = findMax(root,maxi);
        return maxi;
}