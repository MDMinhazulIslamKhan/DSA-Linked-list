#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode *input_tree()
{
    int val;
    cin >> val;
    TreeNode *root;
    if (val == -1)
        root = NULL;
    else
        root = new TreeNode(val);
    queue<TreeNode *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        TreeNode *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        TreeNode *myLeft;
        TreeNode *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new TreeNode(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new TreeNode(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}
TreeNode *convert(int a[], int n, int l, int r)
{
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    TreeNode *root = new TreeNode(a[mid]);
    TreeNode *leftRoot = convert(a, n, l, mid - 1);
    TreeNode *rootRight = convert(a, n, mid + 1, r);
    root->left = leftRoot;
    root->right = rootRight;
    return root;
}
void level_order(TreeNode *root)
{
    if (!root)
    {
        cout << "Empty";
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *f = q.front();
        q.pop();
        cout << f->val << " ";
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}
void insert(TreeNode *&root, int x)
{
    if (root == NULL)
    {
        root = new TreeNode(x);
        return;
    }
    if (x < root->val)
    {
        if (root->left == NULL)
        {
            root->left = new TreeNode(x);
        }
        else
        {
            insert(root->left, x);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new TreeNode(x);
        }
        else
        {
            insert(root->right, x);
        }
    }
}
bool search(TreeNode *root, int x)
{
    if (root == NULL)
        return false;
    if (root->val == x)
        return true;
    if (x < root->val)
        return search(root->left, x);
    else
        return search(root->right, x);
}
int main()
{
    TreeNode *root = input_tree();

    insert(root, 13);
    insert(root, 32);
    insert(root, 27);
    insert(root, 22);
    level_order(root);
    return 0;
}