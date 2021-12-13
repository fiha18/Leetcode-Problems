#include<bits/stdc++.h>
using namespace std;

struct Node
{
    string str;
    bool islock;
    bool isdes;
    vector<Node*> child;
    Node(string v)
    {
        str=v;
        islock=false;
        isdes=false;
    }
};

static void display(Node* root,string st)
{
    if(root)
    {
        if(root->str!=st)
            cout<<" "<<endl;
        else
            cout<<"lock of "<<st <<" "<<root->islock<<endl;
        for(auto it:root->child)
        {
            display(it,st);
            cout<<endl;
        }

    }
}
static void change_des(vector<Node*> vv)
{
    for(auto it:vv)
    {
        cout<< it->str<<" "<<it->islock<<" "<<it->isdes<<" "<<endl;
        it->isdes=true;
    }
    for(auto it:vv)
    {
        cout<<it->str<<" "<<it->islock<<" "<<it->isdes<<" "<<endl;
    }
}

static void locks(Node* root,string st,vector<Node*> &vv)
{
    if(root)
    {
        if(root->str==st)
        {
            if(!root->islock)
        {

            if(!root->isdes)
            {
                change_des(vv);
                cout<<"this will lock the node "<<st<<endl;
                root->islock=true;
                cout<<"lock of this node is "<<root->islock<<endl;
            }
        }
                else
                    cout<<root->str<<" is already locked"<<endl;
        }
        for(auto it:root->child)
        {
            vv.push_back(it);
            locks(it,st,vv);    
        }

    }
}

static void unlock(Node* root,string st)
{
    if(root)
    {
        if(root->str==st)
        {
            if(root->islock)
            {
            root->islock=false;
            root->isdes=false;
            cout<<st <<" unlocked"<<endl;
            }
        }
        for(auto it:root->child)
        {
            unlock(it,st);
        }
    }
}

int main()
{
/*Node *root = new Node("asia");
(root->child).push_back(new Node("India"));
(root->child).push_back(new Node("bhutan"));
(root->child).push_back(new Node("srilanka"));
(root->child).push_back(new Node("bangladesh"));
(root->child[0]->child).push_back(new Node("karnataka"));
(root->child[0]->child).push_back(new Node("tamilnadu"));
(root->child[0]->child).push_back(new Node("kerla"));
(root->child[0]->child)[0]->child.push_back(new Node("bangalore"));
(root->child[0]->child)[1]->child.push_back(new Node("mysore"));
(root->child[0]->child)[2]->child.push_back(new Node("shimoga"));*/
// lock_again(root,"bangalore");
Node *root = new Node("world");
(root->child).push_back(new Node("asia"));
(root->child).push_back(new Node("africa"));
(root->child[0]->child).push_back(new Node("china"));
(root->child[0]->child).push_back(new Node("india"));
//(root->child[0]->child).push_back(new Node("kerla"));
(root->child[1]->child).push_back(new Node("southafrica"));
(root->child[1]->child).push_back(new Node("Egypt"));
vector<Node*> vv;
locks(root,"china",vv);
vv.clear();
locks(root,"india",vv);
unlock(root,"india");
unlock(root,"aisa");//here after locking bengaluru  India cannot be locked
// unlock(root,"bangalore");
display(root,"India");
}