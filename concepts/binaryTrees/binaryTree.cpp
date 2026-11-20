#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// building binary Tree

static int idx = -1;
Node *buildTree(vector<int> preOrder)
{
    idx++;

    if (preOrder[idx] == -1)
        return NULL;

    Node *root = new Node(preOrder[idx]);

    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

// Tree Traversal

// PreOrder Traversal

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

// InOrder Traversal

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// PostOrder Traversal

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// level Order Traversal

void levelOrder(Node *root)
{
    queue<Node *> Q;

    Q.push(root);
    Q.push(NULL);

    while (!Q.empty())
    {
        Node *curr = Q.front();
        Q.pop();

        if (curr == NULL)
        {
            if (!Q.empty())
            {
                cout << endl;
                Q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }
        cout << curr->data << " ";

        if (curr->left != NULL)
        {
            Q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            Q.push(curr->right);
        }
    }
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return 1 + left + right;
}

int heightOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return max(left, right) + 1;
}

int main()
{
    vector<int> preOrderSeq = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *bs = buildTree(preOrderSeq);
    cout << "PreOrder Traversal: ";
    preOrder(bs);
    cout << endl;
    cout << "InOrder Traversal: ";
    inOrder(bs);
    cout << endl;
    cout << "PostOrder Traversal: ";
    postOrder(bs);
    cout << endl;
    cout << "LevelOrder Traversal: " << endl;
    levelOrder(bs);
    cout << endl;
    cout << "Cout of Nodes in the Tree: ";
    cout << countNodes(bs);
    cout << endl;
    cout << "Height of Tree: ";
    cout << heightOfTree(bs);
    return 0;
}