#include "../Data Structures/Utils.cpp"
#include "../Utils.cpp"
#include <iostream>

using namespace std;

/**
 * A good node's value is greater or equal to it's ancestor nodes.
 *
 * Optimal solution:
 * 1. By tracking the maxVal encountered, the good value can be found during the traversal
 *    as opposed to non-optimal solution which does filtering post-traversal.
 *
 * @param maxVal Represents the maximum value encountered so far during traversing a path.
 */
int goodNodes(Node *root, int maxVal) {
    int goodNodeCount = 0;

    if (root == nullptr) {
        return goodNodeCount;
    }

    // Check if the current node is good.
    bool isGood = root->data >= maxVal;

    // Count the current node.
    int goodNodeOnCurrent = isGood ? 1 : 0;
    goodNodeCount += goodNodeOnCurrent;

    if (root->left == nullptr && root->right == nullptr) {
        // Leaf node is found.
        return goodNodeCount;
    }

    if (root->left != nullptr) {
        // Left node is found.
        int newMax = isGood ? root->data : maxVal;
        int goodNodesOnLeft = goodNodes(root->left, newMax);
        goodNodeCount += goodNodesOnLeft;
    }

    if (root->right != nullptr) {
        // Right node is found.
        int newMax = isGood ? root->data : maxVal;
        int goodNodesOnRight = goodNodes(root->right, newMax);
        goodNodeCount += goodNodesOnRight;
    }

    return goodNodeCount;
}

int main() {

    /**
     *         3
     *       /   \
     *      1      4
     *     /      /  \
     *    3      1    5
     */
    Node *root = new Node(3);
    Node *n1 = new Node(1);
    Node *n2 = new Node(4);
    Node *n3 = new Node(3);
    Node *n4 = new Node(1);
    Node *n5 = new Node(5);

    root->left = n1;
    root->right = n2;

    n1->left = n3;

    n2->left = n4;
    n2->right = n5;

    delete n5;
    delete n4;
    delete n3;
    delete n2;
    delete n1;
    delete root;

    /**
     *         3
     *        /
     *       3
     *      /  \
     *     4    2
     */
    // Node *root = new Node(3);
    // Node *n1 = new Node(3);
    // Node *n2 = new Node(4);
    // Node *n3 = new Node(2);

    // // Establish connections
    // root->left = n1;
    // n1->left = n2;
    // n1->right = n3;

    // delete n5;
    // delete n4;
    // delete n3;
    // delete n2;
    // delete n1;
    // delete root;

    cout << "Good nodes: " << goodNodes(root, INT_MIN) << endl;

    return 0;
}

/**
 * Non-optimal solution:
 * 1. This function generates all paths and are later filtered to find good nodes. This is expensive.
 * 2. Checks all the nodes to find "good node" which is expensive.
 */
vector<vector<int>> tracePath(Node *root) {
    vector<vector<int>> paths;
    if (root == nullptr) {
        cout << "Node is Nullptr." << endl;
        return paths;
    }

    // Record the path that ends at current node.
    paths.push_back({root->data});

    if (root->left == nullptr && root->right == nullptr) {
        // Record the path that ends at leaf node.
        return {{root->data}};
    }

    if (root->left != nullptr) {
        if (root->left->data < root->data) {
            return paths;
        }
        // Record the left path.
        vector<vector<int>> leftPaths = tracePath(root->left);
        for (auto leftPath : leftPaths) {
            leftPath.insert(leftPath.begin(), root->data); // Prepend root for readability.
            paths.push_back(leftPath);
        }
    }

    if (root->right != nullptr) {
        if (root->right->data < root->data) {
            return paths;
        }
        // Record the right path.
        vector<vector<int>> rightPaths = tracePath(root->right);
        for (auto rightPath : rightPaths) {
            rightPath.insert(rightPath.begin(), root->data); // Prepend root for readability.
            paths.push_back(rightPath);
        }
    }

    return paths;
}

int countGoodNodes(Node *root) {

    vector<vector<int>> paths = tracePath(root);

    cout << "All paths " << endl;
    printVectorOfVectors(paths);

    // // Filter good nodes
    // for (int i = paths.size() - 1; i >= 0; --i) {
    //     bool remove = false;
    //     int lastIdx = paths[i].size() - 1;
    //     for (int idx = 0; idx < lastIdx; ++idx) {
    //         if (paths[i][idx] > paths[i][lastIdx]) {
    //             remove = true;
    //             break;
    //         }
    //     }
    //     if (remove) {
    //         paths.erase(paths.begin() + i);
    //     }
    // }

    return paths.size();
}
