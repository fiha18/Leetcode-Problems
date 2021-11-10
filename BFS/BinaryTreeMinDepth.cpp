int minDepth(TreeNode* root) {
    if(root == NULL)
       {
        return 0;
       } 
        queue<TreeNode*> q;
        q.push(root);
        // Initialize Min Depth with 1 because if root is present then minDepth is 1 
        int minDepth = 1;
         while(!q.empty())
        {
            int qLen = q.size();
            vector<int> level;
            for(int i=0; i < qLen ; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node!= NULL)
                {
                   level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                // Here if node is not empty then we will check if the node is leaf
                if(node->left == NULL && node->right == NULL)
                {
                    return minDepth;
                }}
            }
            if(level.size()!=0)
            {
                //After every level increase depth value
                minDepth+=1;
            }
        }
    // If there is no leaf node then it has to traverse all the element and it is complete binary tree 
      return minDepth;
    }