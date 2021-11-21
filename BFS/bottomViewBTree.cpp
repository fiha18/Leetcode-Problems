/*  Driver's Code
#include <bits/stdc++.h>
using namespace std;
    struct Node{
        int data;
        Node* left;
        Node* right;
    };
    Node* newNode(int val)
    {
        Node* temp = new Node;
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
Node* buildTree(string str)
{
    if(str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
    {
        ip.push_back(str);
    }
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size())
    {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal != "N")
        {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i>ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N")
        {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}
*/
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
        Node_HD* node;
        node->data = temp->data;
        node->hd = INT_MAX;
        node->left = convert(temp->left);
        node->right = convert(temp->right);
        return node;
        
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
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
            m[hd] = temp->data;
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
