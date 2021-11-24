int height(TreeNode* root){
        // code here
       int max_Depth = 0;
        if(root==NULL)return max_Depth;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int qLen = q.size();
            for(int i=0;i<qLen;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            max_Depth++;}
        return max_Depth;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        int dL = diameterOfBinaryTree(root->left);
        int dR = diameterOfBinaryTree(root->right);
        return max(left_height+right_height,max(dL,dR));
}