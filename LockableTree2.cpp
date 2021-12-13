#include <bits/stdc++.h>
using namespace std;
 
class narytree {
public:
    bool isLock;
    bool isLockable;
    narytree* parent;
    vector<narytree*> children;
    narytree()
    {
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
 
void Lock(narytree* node)
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
 
void unLock(narytree* node)
{
    if (node->isLock == false)
        return;
    narytree* T = node;
    node->isLock = false;
    // marking isLoackable as true for ancestor nodes.
    while (T != NULL) {
        T->isLockable = true;
        T = T->parent;
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

narytree* world = new narytree();
 
narytree* asia = new narytree(world);
narytree* africa = new narytree(world);
    
world->children.push_back(asia);
world->children.push_back(africa);
 

narytree* china = new narytree(world->children[0]);
world->children[0]->children.push_back(china);
narytree* india = new narytree(world->children[0]);
world->children[0]->children.push_back(india);

narytree* southafrica = new narytree(world->children[1]);
world->children[1]->children.push_back(southafrica);

narytree* egypt = new narytree(world->children[1]);
world->children[1]->children.push_back(egypt);
 
    // Locking t4 node.
    Lock(china);
    //    Checking if the t4 node is locked.
    cout << "china node is locked:"
         << ((isLock(china) == true) ? "true" : "false")
         << "\n";
    Lock(india);
    cout << "india node is locked:"
         << ((isLock(india) == true) ? "true" : "false")
         << "\n";
    Lock(asia);
    cout << "asia node is locked:"
         << ((isLock(asia) == true) ? "true" : "false")
         << "\n";
    // Unlocking t4 node.
    unLock(india);
    cout << "india node is unlocked:"
         << ((isLock(india) == false) ? "true" : "false");
    //    Now we should be able to lock the tree.
    unLock(asia);
    cout << endl;
    cout << "asia node is unlocked:"
         << ((isLock(asia) == false) ? "true" : "false");
    cout << endl;
    return 0;
}