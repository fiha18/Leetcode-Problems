vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
         while(!q.empty())
        {
            int qLen = q.size();
            long sum = 0,cnt = 0;
            for(int i=0; i < qLen ; i++)
            {
                TreeNode* node = q.front();
                q.pop(); 
                sum+=node->val;
                cnt++;
                if(node->left != NULL)    
                {q.push(node->left);}
                if(node->right!=NULL)
                {q.push(node->right);}
            }
            res.push_back(sum * 1.0 / cnt);           
         }
        
      return res; 
    }