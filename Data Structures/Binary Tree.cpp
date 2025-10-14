/**
 * Refer: https://archive.codewithharry.com/videos/data-structures-and-algorithms-in-hindi-78/
 */
#include "../Utils.cpp"
#include "Utils.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getPreOrderTree(Node *root) {
    vector<int> nodes;
    if (root != nullptr) {
        nodes.push_back(root->data);
        vector<int> leftSubTree = getPreOrderTree(root->left);
        nodes.insert(nodes.end(), leftSubTree.begin(), leftSubTree.end());
        vector<int> rightSubTree = getPreOrderTree(root->right);
        nodes.insert(nodes.end(), rightSubTree.begin(), rightSubTree.end());
    }

    return nodes;
}

vector<int> getPostOrderTree(Node *root) {
    vector<int> nodes;
    if (root != nullptr) {
        vector<int> leftSubTree = getPostOrderTree(root->left);
        nodes.insert(nodes.begin(), leftSubTree.begin(), leftSubTree.end());
        vector<int> rightSubTree = getPostOrderTree(root->right);
        nodes.insert(nodes.end(), rightSubTree.begin(), rightSubTree.end());
        nodes.push_back(root->data);
    }

    return nodes;
}

vector<int> getInOrderTree(Node *root) {
    vector<int> nodes;
    if (root != nullptr) {
        vector<int> leftSubTree = getInOrderTree(root->left);
        nodes.insert(nodes.begin(), leftSubTree.begin(), leftSubTree.end());
        nodes.push_back(root->data);
        vector<int> rightSubTree = getInOrderTree(root->right);
        nodes.insert(nodes.end(), rightSubTree.begin(), rightSubTree.end());
    }

    return nodes;
}

/**
 * @brief BST Validity operation
 */
bool isBST(Node *root) {
    static Node *previousNode = nullptr;
    if (root != nullptr) {
        // Check if the left tree is BST.
        bool isLeftBST = isBST(root->left);
        if (!isLeftBST)
            return false;

        // Check if the root node is BST. Previous node is last visited node.
        // e.g., If left-most leaf is BST, then "that" recurssion call returns true &
        // we'd be moving up from the leaf node (previous) to parent node (current node).
        bool isRootBST = previousNode == nullptr || root->data >= previousNode->data;
        if (!isRootBST)
            return false;

        // If both left subtree & root are BST, then save the current node as previousNode for further comparisons
        previousNode = root;

        // Check if the right tree is BST.
        bool isRightBST = isBST(root->right);
        if (!isRightBST)
            return false;
        else
            return true;
    } else {
        // Empty tree is a BST.
        return true;
    }
}

/**
 * @brief Search operation (Recursive)
 */
bool isDataPresent(Node *root, int data) {
    if (root != nullptr) {
        if (root->data == data) {
            // Key found
            return true;
        } else if (data < root->data) {
            // Check in the left subtree.
            return isDataPresent(root->left, data);
        } else {
            // Check in the right subtree.
            return isDataPresent(root->right, data);
        }
    } else {
        return false;
    }
}

/**
 * @brief Search operation (Iterative)
 */
bool isDataPresentItr(Node *root, int data) {
    while (root != nullptr) {
        if (data == root->data)
            // Data found.
            return true;
        else if (data < root->data)
            // Despite changing the root pointer (parameter vairable), the original root pointer stays as is. Parameter is pass-by-value.
            root = root->left;
        else
            // Despite changing the root pointer (parameter vairable), the original root pointer stays as is. Parameter is pass-by-value.
            root = root->right;
    }
    return false;
}

/**
 * Recursive insetion.
 *       9
 *      / \
 *     8   15
 *    /    /
 *   7    11
 */
Node *insertNode(Node *target, Node *newNode) {
    if (target == nullptr) {
        // Insertion point is found when target is null.
        // e.g. inserting 16 in the above tree. 15->right is null.
        target = newNode;
    } else if (newNode->data == target->data) {
        // Do nothing.
        cout << "Duplicate key not allowed." << endl;
    } else if (newNode->data < target->data) {
        // Recurse left subtree.
        target->left = insertNode(target->left, newNode);
    } else {
        // Recurse right subtree.
        target->right = insertNode(target->right, newNode);
    }
    return target;
}

/**
 * Iterative insertion
 *
 * @note BST insertion ensures unique position of every new node and nodes are added without moving or replacing existing ones.
 *      - The structure of the tree is maintained.
 *      - The new node would always be inserted as left node.
 *      - No existing node would get replaced as duplicates are not allowed.
 */
bool insertNodeItr(Node *target, Node *newNode) {
    if (target == nullptr) {
        cout << "Target tree is empty. Cannot insert" << newNode->data << endl;
        return false;
    } else {
        // Points to the last visited node.
        Node *lastVisitedNode;

        // Loop exits when target points at null. This is when we have found the parent node under which newNode needs to be inserted.
        while (target != nullptr) {
            lastVisitedNode = target;
            if (newNode->data == target->data) {
                cout << "Node already exists. Cannot add duplicate " << newNode->data << endl;
                return false;
            } else if (newNode->data < target->data) {
                // The target (local pointer) now points to the left.
                // Note: We are not changing the target tree by doing target->left = xyz. We are travering by writing target = target->left;.
                target = target->left;
            } else {
                // The target (local pointer) now points to the right.
                // Note: We are not changing the target tree by doing target->right = xyz. We are travering by writing target = target->right;.
                target = target->right;
            }
        }

        // Given target now points at null, we insert the newNode in its respective place using lastVisitedNode.
        if (newNode->data < lastVisitedNode->data) {
            cout << "Node " << newNode->data << " added to the left of " << lastVisitedNode->data << endl;
            lastVisitedNode->left = newNode;
        } else {
            cout << "Node " << newNode->data << " added to the right of " << lastVisitedNode->data << endl;
            lastVisitedNode->right = newNode;
        }

        return true;
    }
}

/**
 * @note Unique Logic.
 *
 * Tree:
 *         50  ← Find predecessor of this
 *        /  \
 *       30   70
 *      /  \
 *     20   40
 *         /  \
 *        35   45
 *               \
 *                47  ← This is the predecessor!
 *
 * Step by step:
 * 1. root = root->left     → root points to 30
 * 2. root->right != null   → root points to 40
 * 3. root->right != null   → root points to 45
 * 4. root->right != null   → root points to 47
 * 5. root->right == null   → STOP! Found predecessor: 47
 */
Node *getInOrderPredecessor(Node *root) {
    root = root->left;
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

Node *getInorderSuccessor(Node *root) {
    root = root->right;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

/**
 * @param root: The current node being processed. In the first pass, it is root of the whole tree.
 *              In subsequent recursive passes, it is node representing respective subtree.
 * @return Returns the new root of the subtree after deletion.
 */
Node *deleteNode(Node *root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        // Key is in left subtree.
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        // Key is in right subtree.
        root->right = deleteNode(root->right, key);
    } else if (key == root->data) {
        // Key to be delete is found in the root node.

        if (root->left == nullptr && root->right == nullptr) {
            // root node with no children is found i.e leaf node.
            // In this case, replace the deleted node (root) with nullptr.
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            // If the left child is empty that means only right child is present.
            // Store the right child in a temp variable and delete the root.
            // In this case, replace the deleted node (root) with right child.
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            // If the right child is empty that means only left child is present.
            // Store the left child in a temp variable and delete the root.
            // In this case, replace the deleted node (root) with left child.
            Node *temp = root->left;
            delete root;
            return temp;
        } else {
            // Node with two children is found.
            // In this case, replace the deleted node(root) with predecessor node.

            // Find the predecessor node.
            Node *predecessorNode = getInOrderPredecessor(root);

            // Replace the root's data with predecessor node.
            root->data = predecessorNode->data;

            // Delete the predecessor node (located in left subtree of root) from it's old position.
            root->left = deleteNode(root->left, predecessorNode->data);
        }
    }

    return root;
}

int main() {
    /* Tree Structure
           4
          / \
         2   8
        / \ / \
       0  3 5 34
   */
    // Node *root = new Node(4);
    // Node *n1 = new Node(2);
    // Node *n2 = new Node(8);

    // Node *n3 = new Node(0);
    // Node *n4 = new Node(3);
    // Node *n5 = new Node(5);
    // Node *n6 = new Node(34);

    Node *root = new Node(5);
    Node *n1 = new Node(3);
    Node *n2 = new Node(6);

    Node *n3 = new Node(2);
    Node *n4 = new Node(4);
    Node *n5 = new Node(7);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->right = n5;

    if (!isBST(root)) {
        cout << "Tree is not balanced. Cannot perform further actions on this. " << endl;
        return 1;
    }

    cout << "Tree Structure" << endl;
    printTree(root);
    cout << "\n";

    // Print the trees in different orders.
    cout << "Tree (pre order traversal): " << vectorIntToString(getPreOrderTree(root)) << endl;
    cout << "Tree (post order traversal): " << vectorIntToString(getPostOrderTree(root)) << endl;
    cout << "Tree (in order traversal): " << vectorIntToString(getInOrderTree(root)) << endl;
    cout << "\n";

    // Search the tree.
    cout << "Searching for 5 in the tree." << endl;
    cout << (isDataPresentItr(root, 5) ? "5 is present in the tree." : "5 is not present in the tree.") << endl;
    cout << "\n";

    // Insert new node.
    Node *newNode = new Node(-2);
    insertNode(root, newNode);
    cout << "Tree Structure after inserting " << newNode->data << endl;
    printTree(root);
    cout << "\n";

    // Delete node
    deleteNode(root, 3);
    cout << "Tree Structure after deleting 3" << endl;
    printTree(root);
    cout << "\n";

    delete root;
    // delete n1;   // No need to delete this as it's already moved to the root in the delete function.
    delete n2;
    // delete n3; // No need to delete this as it's already moved to the root in the delete function.
    delete n4;
    delete n5;
    delete newNode;

    return 0;
}