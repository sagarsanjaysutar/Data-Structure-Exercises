/**
 * AVL Tree insertion & rotation
 * @ref https://archive.codewithharry.com/videos/data-structures-and-algorithms-in-hindi-82/
 */

#include "Tree-Utils.cpp"
#include <iostream>

using namespace std;

int getHeight(TreeNode *root)
{
    return root == nullptr ? 0 : root->height;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int getBalanceFactor(TreeNode *root)
{
    return root == nullptr ? 0 : getHeight(root->right) - getHeight(root->left);
}

/**
 * @note Right-Right case. A node is added to the right of the right subtree.
 * @brief Left rotate with respect to the unbalanced node (root).
 *
 * In the below example, the unbalanced node is 9 (calculated using balancing factor). Thus is the below tree left-rotated.
 * Before:                After:
 *   9                     15
 *  / \                   /  \
 * 8  15        →        9    20
 *    /  \             / \     \
 *   11  20           8  11    21
 *        \
 *        21
 */
TreeNode *leftRotate(TreeNode *root)
{
    // #00. The right child of the root will become the root.
    TreeNode *rootRight = root->right;

    // #01. Save the left child of rootRight (will be reattached later to maintain BST property).
    TreeNode *rootRightLeft = rootRight->left;

    // #02. Perform rotation: The right of the root now becomes the new root. The old root now goes to the left subtree.
    rootRight->left = root;

    // #03. Reattach rootRightLeft to new position. This move maintains predecessor sequence.
    root->right = rootRightLeft;

    // #04. Update the heights. (+1: Find the height of the tallest child subtree + Add 1 for the current node)
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    rootRight->height = max(getHeight(rootRight->right), getHeight(rootRight->left)) + 1;

    // Return the Updated root.
    return rootRight;
}

/**
 * @note Left-Left case. A node is added to left of left subtree.
 * @brief Right rotate with respect to the unbalanced node (root).
 *
 * Before:                After:
 *       9                    9
 *      / \                  / \
 *     8   15               7   15
 *    /    /               / \   /
 *   7    11              6   8 11
 *  /
 * 6
 */
TreeNode *rightRotate(TreeNode *root)
{
    // #00 The left child of the root will become the root.
    TreeNode *rootLeft = root->left;

    // #01. Save the right child of the rootLeft (will be reattached later to maintain BST property).
    TreeNode *rootLeftRight = rootLeft->right;

    // #02. Perform rotation: The left of the root now becomes the new root. The old root now goes to the right subtree.
    rootLeft->right = root;

    // #03. Reattached the rootLeftRight to new position. This move maintains predecessor sequence.
    root->left = rootLeftRight;

    // #04. Update the height. (+1: Find the height of the tallest child subtree + Add 1 for the current node)
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    rootLeft->height = max(getHeight(rootLeft->right), getHeight(rootLeft->left)) + 1;

    // #05. Return the updated node.
    return rootLeft;
}

TreeNode *insert(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return new TreeNode(key);
    }

    // #00. Traverse through the subtree using recursion.
    if (key < root->val)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root; // Duplicate key
    }

    // #02. Update the height. (+1: Find the height of the tallest child subtree + Add 1 for the current node)
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;

    // #03. Check balance factor after insertion in #00. Rotate accordingly.
    int bf = getBalanceFactor(root);
    if (bf < -1)
    {
        // Left heavy tree.
        if (key < root->left->val)
        {
            // Left-left case has occurred; perform right-rotation with respect to root node.
            root = rightRotate(root);
        }
        else if (key > root->left->val)
        {
            // Left-right case has occurred; perform right rotation on child of root followed by left-rotation on root.
            root->left = rightRotate(root->left);
            root = leftRotate(root);
        }
    }

    if (bf > 1)
    {
        // Right heavy tree.
        if (key > root->right->val)
        {
            // Right-Right case has occurred; perform left-rotation with respect to root node.
            root = leftRotate(root);
        }
        else if (key < root->right->val)
        {
            // Right-Left case has occurred; perform left rotate on child of root followed by right-rotation on root.
            root->right = leftRotate(root->right);
            root = rightRotate(root);
        }
    }

    return root;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    printTree(root);
    return 0;
}