/**
 * AVL Tree insertion & rotation
 * @ref https://archive.codewithharry.com/videos/data-structures-and-algorithms-in-hindi-82/
 */

#include "Utils.cpp"
#include <iostream>

using namespace std;

int getHeight(Node *root) {
    return root == nullptr ? 0 : root->height;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int getBalanceFactor(Node *root) {
    return root == nullptr ? 0 : getHeight(root->right) - getHeight(root->left);
}

/**
 * @note Right-Right case. A node is added to the right of the right subtree.
 * @brief Left rotate with respect to the unbalanced node (root).
 *
 * Before:                After:
 *   9                     15
 *  / \                   /  \
 * 8  15        →        9    20
 *    /  \             / \     \
 *   11  20           8  11    21
 *        \
 *        21
 */
Node *leftRotate(Node *root) {
    // #00. The right child of the root will become the root.
    Node *rootRight = root->right;

    // #01. Save the left child of rootRight (will be reattached later to maintain BST property).
    Node *rootRightLeft = rootRight->left;

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
Node *rightRotate(Node *root) {
    // #00 The left child of the root will become the root.
    Node *rootLeft = root->left;

    // #01. Save the right child of the rootLeft (will be reattached later to maintain BST property).
    Node *rootLeftRight = rootLeft->right;

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

Node *insert(Node *root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    // #00. Traverse through the subtree using recursion.
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    } else {
        return root; // Duplicate key
    }
    // #02. Update the height. (+1: Find the height of the tallest child subtree + Add 1 for the current node)
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;

    // #03. Check the balance factor and accordingly rotate the tree.
    int bf = getBalanceFactor(root);
    cout << "Balance factor at " << root->data << " " << bf << endl;
    // #04. Insertion has happened by this point & recursion in #00 has ended.
    // We have reached leaf node. root now represents that leaf node & not the original tree root.
    if (bf < -1 && key < root->left->data) {
        cout << "Left-left: Imbalance detected at " << root->data << " " << bf << endl;
        // Left-left case has occured as key being inserted is less than left of root i.e. the key is inserted to the left of left subtree.
        // Use right-rotate
        root = rightRotate(root);
    } else if (bf > 1 && key > root->right->data) {
        // Right-Right case has occured as key being inserted is greater than the right of root. i.e. the key is inserted to the right of right subtree.
        // Use left rotate
        cout << "Right-Right: Imbalance detected at " << root->data << " " << bf << endl;
        root = leftRotate(root);
    } else if (bf < -1 && key > root->left->data) {
        // Left-right case has occured as bf is -1 & key being inserted is greater than left of root. i.e. the key is inserted to the right of left subtree.
        // Left-rotate with the respect to the child of imbalanced node, followed by right-rotate with respect to imbalanced node.
        cout << "Left-Right: Imbalance detected at " << root->data << " " << bf << endl;
        root->left = leftRotate(root->left);
        root = rightRotate(root);

    } else if (bf > 1 && key < root->right->data) {
        // Right-left case has occured as bf is > 1 & key being inserted is less than the right of root i.e. the key is inserted to the left of right subtree.
        // Right-rotate with respect to the child of imbalanced node, followed by left-rotate with respect to imbalanced node.
        cout << "Right-Left: Imbalance detected at " << root->data << " " << bf << endl;
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }

    return root;
}

int main() {
    Node *root = new Node(10);
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