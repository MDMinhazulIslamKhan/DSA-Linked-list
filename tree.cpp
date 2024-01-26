#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void preOrderTraverse(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}
void postOrderTraverse(Node *root)
{
    if (!root)
    {
        return;
    }
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->val << " ";
}
void inOrderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    };
    inOrderTraverse(root->left);
    cout << root->val << " ";
    inOrderTraverse(root->right);
}
void levelOrder(Node *root)
{
    if (!root)
    {
        cout << "Empty";
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        cout << f->val << " ";
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}
Node *inputTree()
{
    int left, right;
    cin >> left;

    Node *root;
    if (left == -1)
        root = NULL;
    else
        root = new Node(left);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (cin >> left >> right)
    {
        Node *f = q.front();
        q.pop();
        if (left == -1)
        {
            f->left = NULL;
        }
        else
        {
            Node *leftNode = new Node(left);
            f->left = leftNode;
            q.push(leftNode);
        }
        if (right == -1)
        {
            f->right = NULL;
        }
        else
        {
            Node *rightNode = new Node(right);
            f->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
int countTree(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int l = countTree(root->left);
    int r = countTree(root->right);
    return l + r + 1;
}
int countLeaf(Node *root)
{
    if (!root)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int l = countLeaf(root->left);
    int r = countLeaf(root->right);
    return l + r;
}
int myHightOfTree(Node *root, int depth)
{
    if (!root)
    {
        return depth;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return depth;
    }

    int l = myHightOfTree(root->left, depth + 1);
    int r = myHightOfTree(root->right, depth + 1);
    if (l > r)
        return l;
    else
        return r;
}
int hightOfTree(Node *root)
{
    if (!root)
    {
        return 0;
    }

    int l = hightOfTree(root->left);
    int r = hightOfTree(root->right);

    return max(l, r) + 1;
}
void printLeaf(Node *root)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        cout << root->val << " ";
    }
    printLeaf(root->left);
    printLeaf(root->right);
}
int main()
{
    Node *root = inputTree();
    printLeaf(root);
    return 0;
}
