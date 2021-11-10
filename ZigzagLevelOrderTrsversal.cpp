
/*
The functioning will be similar to level order traversal , Introduction of flag to keep track of leftToRight will make it possible for zigzag traversal.

*/
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
        if(root == NULL)
        {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        // A leftToRight flag is introduced as true because level 0 - left To Right m then level 1 - right To left , then so on.
        bool leftToRight = true;
        while(!q.empty())
        {
            int qLen = q.size();
            //Now we declare level vector of size similar to queue
            vector<int> level(qLen);
            for(int i=0; i < qLen ; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                // here checking first if leftToRight is true then store in forward order in level vector else store in reverse order
                int index = leftToRight ? i : (qLen - i - 1);
              if(node != NULL)
              { // storing value of node in level vector on the above condition basis
                level[index] = (node->val);
                if(node->left)
                {q.push(node->left);}
                if(node->right)
                {q.push(node->right);}}
            }
        // changing leftToRight flag if true then false or false then true
        leftToRight = !leftToRight;
        res.push_back(level);
        }
      return res; 
    }