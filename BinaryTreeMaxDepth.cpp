int maxDepth(TreeNode* root) {
    if(root == NULL)
       {
        return 0;
       } 
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
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
                }
            }
            if(level.size()!=0)
            {
                depth+=1;
            }
        }
      return depth;
    }