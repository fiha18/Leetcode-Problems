#include <bits/stdc++.h>
using namespace std;
    struct Node{
        int data;
       vector<Node*> child;
    };
    Node* newNode(int val)
    {
        Node* temp = new Node;
        temp->data = val;
        return temp;
    }
    struct Node_Lock{
        int data;
        bool isLocked;
        int lockedDescendantCount;
        vector<Node_Lock*> child;
    };
    Node_Lock* convert(Node* temp)
    {
        if(temp == NULL)
        {return NULL;}
        Node_Lock* node;
        node->data = temp->data;
        node->isLocked = false;
        node->lockedDescendantCount = 0;
       for (int i = 0; i < temp->child.size(); ++i)
       {
        node->child[i] = convert(temp->child[i]);
       }
        return node;  
    }
    Node* levelOrder(Node* root,int X) {
        queue<Node*> q;
        q.push(root);
         while(!q.empty())
        {
            int qLen = q.size();
            for(int i=0; i < qLen ; i++)
            {
                Node* node = q.front();
                q.pop();
                if(node!= NULL)
                {
                    if(node->data == X)
                        {return node;}
                    for(int k = 0; k < node->child.size();k++)
                    {
                        q.push(node->child[i]);
                    }
                }
            }
        }
    }
    void pathFromRoot(int X, vector<Node_Lock*> &ancestor, Node_Lock* root)
    {
        if(root->data == node->data)
            return;
        for (int i = 0; i < root->child.size(); ++i)
        {
            if(root->child[i])
            {
            ancestor.push_back(root->child[i]);
            pathFromRoot(node,ancestor,root->child[i]);
            }
        }
    }
    bool Lock(int X, Node* root)
    {
        Node_Lock* root_Lock = convert(root);
        Node* node = levelOrder(root,X);
        vector<Node_Lock*> ancestor;
        pathFromRoot(X,ancestor,root);
        int unlockedCountAncestor = 0;
        for (int i = 0; i < ancestor.size(); ++i)
        {
            if(ancestor[i]->isLocked == false)
                unlockedCountAncestor++;
        }

        if(unlockedCountAncestor == ancestor.size() && node_Lock->lockedDescendantCount == 0)
        {
            node_Lock->isLocked == true;
            for (int i = 0; i < ancestor.size(); ++i)
            {
                ancestor[i]->lockedDescendantCount+=1;
            }
            return true;
        }
        return false;
    }
    bool Unlock(Node* X,Node* root)
    {
        Node_Lock* root_Lock = convert(root);
        Node_Lock* node_Lock = convert(X);
        if(node_Lock->isLocked == false)
        {
            return false;
        }
        vector<Node_Lock*> ancestor;
        pathFromRoot(node_Lock,ancestor,root_Lock);
        for (int i = 0; i < ancestor.size(); ++i)
        {
            ancestor[i]->lockedDescendantCount-=1;
        }
        node_Lock->isLocked = false;
        return true;
    }
int main()
{
    Node* root = newNode(1);
    vector<Node*> rootChild;
    Node* rootChild01 = newNode(2);
    Node* rootChild02 = newNode(3);
    Node* rootChild03 = newNode(4);
    rootChild.push_back(rootChild01);
    rootChild.push_back(rootChild02);
    rootChild.push_back(rootChild03);
    root->child = rootChild;
    vector<Node*> rootChild1;
    Node* rootChild11 = newNode(5);
    Node* rootChild12 = newNode(6);
    Node* rootChild13 = newNode(7);
    rootChild1.push_back(rootChild11);
    rootChild1.push_back(rootChild12);
    rootChild1.push_back(rootChild13);
    root->child[0]->child = rootChild1;
    vector<Node*> rootChild2;
    Node* rootChild21 = newNode(8);
    Node* rootChild22 = newNode(9);
    Node* rootChild23 = newNode(10);
    rootChild2.push_back(rootChild21);
    rootChild2.push_back(rootChild22);
    rootChild2.push_back(rootChild23);
    root->child[1]->child = rootChild2;
    vector<Node*> rootChild3;
    Node* rootChild31 = newNode(11);
    Node* rootChild32 = newNode(12);
    Node* rootChild33 = newNode(13);
    rootChild3.push_back(rootChild31);
    rootChild3.push_back(rootChild32);
    rootChild3.push_back(rootChild33);
    root->child[2]->child = rootChild3;
    Node* X = root->child[1]->child[0];
    Node_Lock* root_Lock = convert(root);
    Node_Lock* node_Lock = convert(X);
    vector<Node_Lock*> ancestor;
    pathFromRoot(node_Lock,ancestor,root_Lock);
   /* 
    bool l1 = Lock(root->child[1]->child[0],root);
    bool l2 = Lock(root->child[1]->child[0],root);
    bool ul1 = Unlock(root->child[1]->child[0],root);
    cout << l1 << l2 << ul1 << endl;*/
    return 0;
}