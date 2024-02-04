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
void preOrderTraverse(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}
void postOrderTraverse(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->val << " ";
}
void inOrderTraverse(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    };
    inOrderTraverse(root->left);
    cout << root->val << " ";
    inOrderTraverse(root->right);
}
void levelOrder(TreeNode *root)
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
void printSingleLevel(TreeNode *root, int line)
{
    if (!root)
    {
        return;
    }
    if (line == 0)
    {
        cout << root->val;
        return;
    }
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        TreeNode *f = q.front().first;
        int currentLevel = q.front().second;
        if (currentLevel == line)
            cout
                << f->val << " ";
        q.pop();
        if (f->left)
            q.push({f->left, currentLevel + 1});
        if (f->right)
            q.push({f->right, currentLevel + 1});
    }
}
TreeNode *inputTree()
{
    int left, right;
    cin >> left;

    TreeNode *root;
    if (left == -1)
        root = NULL;
    else
        root = new TreeNode(left);
    queue<TreeNode *> q;
    if (root)
        q.push(root);
    while (cin >> left >> right)
    {
        TreeNode *f = q.front();
        q.pop();
        if (left == -1)
        {
            f->left = NULL;
        }
        else
        {
            TreeNode *leftNode = new TreeNode(left);
            f->left = leftNode;
            q.push(leftNode);
        }
        if (right == -1)
        {
            f->right = NULL;
        }
        else
        {
            TreeNode *rightNode = new TreeNode(right);
            f->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
int countTree(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int l = countTree(root->left);
    int r = countTree(root->right);
    return l + r + 1;
}
int countLeaf(TreeNode *root)
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
int myHightOfTree(TreeNode *root, int depth)
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
int hightOfTree(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int l = hightOfTree(root->left);
    int r = hightOfTree(root->right);

    return max(l, r) + 1;
}
void printLeaf(TreeNode *root)
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
int sumOfTree(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 0;
    }
    int l = sumOfTree(root->left);
    int r = sumOfTree(root->right);
    return root->val + l + r;
}
int main()
{
    TreeNode *root = inputTree();
    printLeaf(root);
    return 0;
}
