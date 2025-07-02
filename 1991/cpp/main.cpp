#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    char tag;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char tag) : tag(tag), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode *now);
void inorder(TreeNode *now);
void postorder(TreeNode *now);

int main()
{
    int N;
    cin >> N;

    unordered_map<char, TreeNode *> nodes;

    for (int i = 0; i < N; i++)
    {
        char root, left, right;
        cin >> root >> left >> right;

        if (nodes.find(root) == nodes.end())
        {
            nodes[root] = new TreeNode(root);
        }

        if (left != '.')
        {
            if (nodes.find(left) == nodes.end())
            {
                nodes[left] = new TreeNode(left);
            }
            nodes[root]->left = nodes[left];
        }

        if (right != '.')
        {
            if (nodes.find(right) == nodes.end())
            {
                nodes[right] = new TreeNode(right);
            }
            nodes[root]->right = nodes[right];
        }
    }

    preorder(nodes['A']);
    cout << "\n";
    inorder(nodes['A']);
    cout << "\n";
    postorder(nodes['A']);
    cout << "\n";

    return 0;
}

void preorder(TreeNode *now)
{
    if (!now)
        return;

    cout << (now->tag);
    preorder(now->left);
    preorder(now->right);
}

void inorder(TreeNode *now)
{
    if (!now)
        return;

    inorder(now->left);
    cout << (now->tag);
    inorder(now->right);
}

void postorder(TreeNode *now)
{
    if (!now)
        return;

    postorder(now->left);
    postorder(now->right);
    cout << (now->tag);
}
