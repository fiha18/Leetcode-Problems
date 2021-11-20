vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return  res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            s.pop();
            res.push_back(temp->val);
            if(temp->right)
            {
                s.push(temp->right);
            }
            if(temp->left)
            {
                s.push(temp->left);
            }
        }
        return res;
    }