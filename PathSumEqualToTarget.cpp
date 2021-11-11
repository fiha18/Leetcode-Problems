 /*
Given the root of a binary tree and an integer targetSum,
return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
 */
  bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
        {
            if(root->val == targetSum)
            {
                return true;
            }
        }
        //Recursion Ka Khel hai bhai sb
        return ((hasPathSum(root->left, targetSum - root->val)) || (hasPathSum(root->right, targetSum - root->val)));
    }