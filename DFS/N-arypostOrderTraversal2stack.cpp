 class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
 vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<Node*> s;
        s.push(root);
        while(!s.empty())
        {
            Node* temp = s.top();
            s.pop();
            res.push_back(temp->val);
            for(int i=0;i<(temp->children).size();i++)
            {
                s.push((temp->children)[i]);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }