

bool isSymmetric(TreeNode* root) {
        // If it is null then it is automatically symmetric 
        if(root==NULL) return true;
        // Using QUEUE because of FIFO
        queue<TreeNode*> q;
        // Pushing root of left sub tree
        q.push(root->left);
        // Pushing root of right sub tree
        q.push(root->right);
        while(!q.empty())
        {
            // Poping front value - We make sure it is from left sub tree
            TreeNode* temp1 = q.front();
            q.pop();
            // Poping next front value - We make sure it is from right sub tree
            TreeNode* temp2 = q.front();
            q.pop();
            // if both value are null we continue
            if(temp1==NULL && temp2==NULL)
            {
                continue;
            }
            // if any of them are NULL then return false
            if((temp1==NULL && temp2!=NULL) || (temp2==NULL && temp1!=NULL))
                return false;
            // if poped node have different values 
            if(temp1->val != temp2->val)
                return false;

            // Below we maintain the sequence front of the queue from left sub tree and next front form the right sub tree

            // push to queue left node of above poped from left subtree
            q.push(temp1->left);
            // push to queue right node of above poped from right subtree
            q.push(temp2->right);
            // push to queue right node of above poped from left subtree
            q.push(temp1->right);
            // push to queue left node of above poped from right subtree
            q.push(temp2->left);
        }
        return true;
    }