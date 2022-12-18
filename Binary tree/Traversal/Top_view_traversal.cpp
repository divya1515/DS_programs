#include <bits/stdc++.h>
#include <queue>
using namespace std;
class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node *next;
    Node(char data)
    {

        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void Top_view_traversal(Node *&root)
{
    // here need to insert only one data in map
    map<int, char> nodes; 

    queue<pair<Node *, pair<int, int>>> q; // node , {hd,level}
    //level traversal with the help of queue thus queue is taken
    Node *p = root;
    q.push({p, {0, 0}});// initial root node has 0 horizontal distance and 0 level
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        Node *n = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;
        if(nodes.find(hd)==nodes.end())// if for any key its data value is not present then need to insert data for that key
        {
        nodes[hd]=n->data;
        }
        if (n->left != NULL)
        {
            q.push({n->left, {hd - 1, level + 1}});
        }
        if (n->right != NULL)
        {
            q.push({n->right, {hd + 1, level + 1}});
        }
    }
    for (auto &i : nodes)
    {
        cout<<i.second;
    }
}
int main()
{
    Node *root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->right = new Node('E');
    root->left->left = new Node('D');
    root->left->left->left = new Node('H');
    root->left->left->right = new Node('I');
    root->right->right = new Node('G');
    root->right->right->right = new Node('Y');
    root->right->left = new Node('F');
    root->right->left->left = new Node('M');
    root->right->left->right = new Node('U');
    Top_view_traversal(root);
}
