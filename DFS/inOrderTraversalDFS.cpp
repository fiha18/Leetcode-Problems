vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        // Empty Stack
        stack<TreeNode*> st;
        // initalize Current node as Root
        TreeNode* curr = root;
        // If stack is not empty
        while(curr!=NULL || !st.empty())
        {
            // For going deep into left subtree first till left not NULL
            while(curr !=NULL)
            {
                st.push(curr);
                // Left Subtree
                curr = curr->left;
            }
            // After traversing to deep Left and Stack is not empty
            // Pop out top element
            curr = st.top();
            st.pop();
            // Value push to vector
            inOrder.push_back(curr->val);

            // Getting Right sub tree
            curr = curr->right;
        }
        return inOrder;
    }