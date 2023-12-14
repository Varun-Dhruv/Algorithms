#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr){};
    TreeNode(int data, TreeNode *left, TreeNode *right) : val(data), left(left), right(right){};
};
// recursive Traversals
void inorderTraversal(TreeNode *root, vector<int> &traversal)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left, traversal);
    traversal.push_back(root->val);
    inorderTraversal(root->right, traversal);
}
void preorderTraversal(TreeNode *root, vector<int> &traversal)
{
    if (root == nullptr)
        return;
    traversal.push_back(root->val);
    preorderTraversal(root->left, traversal);
    preorderTraversal(root->right, traversal);
}
void postorderTraversal(TreeNode *root, vector<int> &traversal)
{
    if (root == nullptr)
        return;
    preorderTraversal(root->left, traversal);
    preorderTraversal(root->right, traversal);
    traversal.push_back(root->val);
}

// non recursive traversals
void morrisTraversalPreorder(TreeNode *root, vector<int> &traversal)
{
    while (root)
    {
        if (root->left == nullptr)
        {
            traversal.push_back(root->val);
            root = root->right;
        }
        else
        {
            TreeNode *curr = root->left;
            while (curr->right && curr->right != root)
            {
                curr = curr->right;
            }
            if (curr->right == root)
            {
                curr->right = nullptr;
                root = root->right;
            }
            else
            {
                curr->right = root;
                root = root->left;
            }
        }
    }
}
void morrisTraversalInorder(TreeNode* root,vector<int>& traversal){
    
}
int KthLargest(TreeNode *root, int k)
{
    TreeNode *curr = root;
    TreeNode *KLarg = NULL;
    int cnt = 0;
    while (curr != nullptr)
    {
        if (curr->right == nullptr)
        {
            if (++cnt == k)
            {
                KLarg = curr;
            }
            curr = curr->left;
        }
        else
        {
            TreeNode *succ = curr->right;
            while (succ->left != nullptr && succ->left != curr)
                succ = succ->left;
            if (succ->left == nullptr)
            {
                succ->left = curr;
                curr = curr->right;
            }
            else
            {
                succ->left = nullptr;
                if (++cnt == k)
                    KLarg = curr;
                curr = curr->left;
            }
        }
    }
    return KLarg->val;
}

int main()
{

    return 0;
}