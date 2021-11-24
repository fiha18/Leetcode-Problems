/*
Check if SameTree - Theoritically A Unique Binary tree can be formed from Preorder and Inorder Traversal
We can check if the Preorder and Inorder traversal of both the tree are equal then they are same

But Interms of Solving it with code 

    Iterative Approach :
        Using Queue and its FIFO property
        
        Checking for the NULL case first :  both root are null they are same
        
        Pushing the root of both tree in queue
        
        Iterating within queue untill it is empty

        Poping the first 2 nodes from queue We will maintain order in the queue such that:
                        Value of the left subtree of first tree are compared with Value of the left subtree of first tree are compared
                        Value of the right subtree of first tree are compared with Value of the right subtree of first tree are compared

    
        Checking for the NULL case for poped node:  either of the root is null then Trees are not similar
                                                    if root value of both the tree are not equal trees are not same

        Pushing nodes from left and right subtree with ordered maintained


        Time Complexity     - O(N) - N is the number of nodes
        Space Complexity    - O(N) Worst case - For Skew Tree then all the nodes will be pushed in queue

*/

bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q == NULL)
            return true;
        queue<TreeNode*> queue;
        queue.push(p);
        queue.push(q);
        while(!queue.empty())
        {
            TreeNode* temp1 = queue.front();
            queue.pop();
            TreeNode* temp2 = queue.front();
            queue.pop();
            
            if(temp1 == NULL && temp2 == NULL)
                continue;
            if((temp1!=NULL && temp2==NULL) || (temp1==NULL && temp2!=NULL))
                return false;
            if(temp1->val != temp2->val)
                return false;
            
            queue.push(temp1->left);
            
            queue.push(temp2->left);
            
            queue.push(temp1->right);
            
            queue.push(temp2->right);
            
        }
        return true;
    }