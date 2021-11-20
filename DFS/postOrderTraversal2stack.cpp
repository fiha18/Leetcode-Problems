  
     vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
        {
            return res;
        }
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode* temp = s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->left)s1.push(temp->left);
            if(temp->right)s1.push(temp->right);
        }
        while(!s2.empty())
        {
             TreeNode* temp = s2.top();
             s2.pop();
             res.push_back(temp->val);

        }
        return res;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
        {
            return res;
        }
        stack<TreeNode*> s1;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode* temp = s1.top();
            s1.pop();
            res.push_back(temp->val);
            if(temp->left)s1.push(temp->left);
            if(temp->right)s1.push(temp->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }