#include <bits/stdc++.h>
using namespace std;
 
class narytree {
public:
    string name;
    bool isLock;
    bool isLockable;
    narytree* parent;
    int uid;
    vector<narytree*> children;
    narytree(string val)
    {
        name = val;
        isLock = false;
        isLockable = true;
        parent = NULL;
    }
    narytree(narytree* parent)
    {
        isLock = false;
        isLockable = true;
        this->parent = parent;
    }
};
 
bool isLock(narytree* node) { return node->isLock; }
 
void Lock(narytree* node,int uid)
{
    
    if (node->isLockable == false)
        return;
 
    narytree* T = node;
    bool flag = false;
    while (T != NULL) {
        if (T->isLock == true) {
            flag = true;
            break;
        }
        T = T->parent;
    }
    if (flag)
        return;
    else {
        node->isLock = true;
        node->uid = uid;
        T = node;
        // marking isLockable as false for ancestor nodes.
        while (T != NULL) {
            T->isLockable = false;
            T = T->parent;
        }
    }
}
 
void unLock(narytree* node,int uid)
{
    if(node->uid == uid && node->isLock==true){  
    if (node->isLock == false)
        return;
    narytree* T = node;
    node->isLock = false;
    // marking isLoackable as true for ancestor nodes.
    while (T != NULL) {
        T->isLockable = true;
        T = T->parent;
    }}
}
 


void upgradeLock(narytree* node,int uidVal)
{
    
    if (node->isLockable == false)
        return;
 
    narytree* T = node;
    bool flag = false;
    while (T != NULL) {
        if (T->isLock == true) {
            flag = true;
            break;
        }
        T = T->parent;
    }
    if (flag)
        return;
    else {
        node->isLock = true;
        T = node;
        // marking isLockable as false for ancestor nodes.
        while (T != NULL) {
            T->isLockable = false;
            T = T->parent;
        }
    }
}
int main()
{
    // Creating N-Array Tree
    /*narytree* root = new narytree();
 
    narytree* t1 = new narytree(root);
    narytree* t2 = new narytree(root);
    narytree* t3 = new narytree(root);
 
    root->children.push_back(t1);
    root->children.push_back(t2);
    root->children.push_back(t3);
 
    narytree* t5 = new narytree(root->children[0]);
    root->children[0]->children.push_back(t5);
    narytree* t4 = new narytree(root->children[1]);
    root->children[1]->children.push_back(t4);*/

narytree* world = new narytree("world");
 
narytree* asia = new narytree(world);
asia->name = "asia";
narytree* africa = new narytree(world);
africa->name = "africa";
world->children.push_back(asia);
world->children.push_back(africa);

narytree* china = new narytree(world->children[0]);
china->name = "china";
world->children[0]->children.push_back(china);

narytree* india = new narytree(world->children[0]);
india->name = "india";
world->children[0]->children.push_back(india);

narytree* southafrica = new narytree(world->children[1]);
southafrica->name = "southafrica";
world->children[1]->children.push_back(southafrica);

narytree* egypt = new narytree(world->children[1]);
egypt->name = "egypt";
world->children[1]->children.push_back(egypt);
 

narytree* chinas1 = new narytree(world->children[0]->children[0]);
chinas1->name = "chinas1";
world->children[0]->children[0]->children.push_back(chinas1);
narytree* chinas2 = new narytree(world->children[0]->children[0]);
chinas2->name = "chinas2";
world->children[0]->children[0]->children.push_back(chinas2);

narytree* indias1 = new narytree(world->children[0]->children[1]);
indias1->name = "indias1";
world->children[0]->children[1]->children.push_back(indias1);


narytree* indias2 = new narytree(world->children[0]->children[1]);
indias2->name = "indias2";
world->children[0]->children[1]->children.push_back(indias2);
    // Locking t4 node.
    Lock(china,9);
    //    Checking if the t4 node is locked.
    cout << china->name<<" node is locked:"
         << ((isLock(china) == true) ? "true" : "false")
         << "\n";
    Lock(india,9);
    cout <<india->name <<" node is locked:"
         << ((isLock(india) == true) ? "true" : "false")
         << "\n";
    Lock(asia,8);
    cout << asia->name<<" node is locked:"
         << ((isLock(asia) == true) ? "true" : "false")
         << "\n";
    Lock(indias1,9);
    cout <<indias1->name <<" node is locked:"
         << ((isLock(indias1) == true) ? "true" : "false")
         << "\n";
    // Unlocking t4 node.
    unLock(india,9);
    cout << india->name<<" node is unlocked:"
         << ((isLock(india) == false) ? "true" : "false");
    //    Now we should be able to lock the tree.
    unLock(asia,9);
    cout << endl;
    cout << asia->name<<" node is unlocked:"
         << ((isLock(asia) == false && asia->isLockable == false) ? "true" : "false");
    cout << endl;
    return 0;
}