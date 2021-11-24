//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   if(root == NULL)
   {
       return res;
   }
   queue<Node*> q;
   q.push(root);
   while(!q.empty())
   {
      int qLen = q.size();
      for(int i=1; i<=qLen ;i++)
      {
           Node *temp = q.front();
           q.pop();
           // For Left View - if i = 1 i.e. first element in level order traversal at each level
           // For Right View - if i = qLen i.e. last element in level order traversal at each level
           if(i==1)
           {
               res.push_back(temp->data);
           }
           if(temp->left)
           {
               q.push(temp->left);
           }
           if(temp->right)
           {
               q.push(temp->right);
           }
    
      }
   }
   return  res;
}