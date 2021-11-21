 struct Node_HD{
        int data;
        int hd;
        Node_HD* left;
        Node_HD* right;
    };
    Node_HD* convert(Node* temp)
    {
        if(temp == NULL)
        {return NULL;}
        Node_HD* node = new Node_HD;
        node->data = temp->data;
        node->hd = INT_MAX;
        node->left = convert(temp->left);
        node->right = convert(temp->right);
        return node;
        
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> res;
        if(root==NULL)
        {
            return res;
        }
        Node_HD* root_hd = convert(root);
        int hd = 0;
        map<int,int> m;
        queue<Node_HD*> q;
        root_hd->hd = hd;
        q.push(root_hd);
        while(!q.empty())
        {
            Node_HD* temp = q.front();
            q.pop();
            hd = temp->hd;
            //For bottom View we will update and check the last value of Key
            // For top View if hd key exist in the map then the existing is the top view value 
            // Just check if key exist or not if not exist then only insert key value pair else do nothing
            if(m.find(hd)==m.end())
            {
                m[hd] = temp->data;
            }
            if(temp->left)
            {
                temp->left->hd = hd -1;
                q.push(temp->left);
            }
            if(temp->right)
            {
                temp->right->hd = hd + 1;
                q.push(temp->right);
            }
        }
        map<int,int>::iterator itr;
        for(itr = m.begin();itr!=m.end();itr++)
        {
           res.push_back(itr->second); 
        }
        return res;
    }