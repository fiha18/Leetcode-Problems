vector<vector<int>> levelOrder(TreeNode* root) {
        // Level Order Traversal of B Tree is BFS of B Tree
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
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
                res.push_back(level);
            }
        }
      return res;  
    }
