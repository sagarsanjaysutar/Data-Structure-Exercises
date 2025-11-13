#include "../Data Structures/Utils.cpp"
#include <iostream>

using namespace std;

/**
 * @brief Inefficient
 *
 * Traces all the paths of the tree. Starting from each node.
 * e.g. the paths of the below trees are
 *  - 9 → 8 → 7
 *  - 8 → 7
 *  - 9 → 15 → 11
 *  - 15 → 11
 *
 *       9
 *      / \
 *     8   15
 *    /    /
 *   7    11
 *
 * This method is expensive.
 */
vector<vector<int>> traceAllPaths(Node *root, int sumUntilNow, int targetSum) {
    cout << "\n\npathSum called: Node: " << root->data << " sumUntilNow: " << sumUntilNow << " targetSum: " << targetSum << endl;
    int sum;
    vector<vector<int>> paths;

    if (!root)
        return paths;

    sum = root->data + sumUntilNow;

    // Sum found. Record the node.
    if (targetSum == sum) {
        cout << "Recording " << root->data << endl;
        paths.push_back({root->data});
    }

    // If sum is not found, continue exploring existing path which started from the parent.
    if (root->left) {
        cout << "Calling path sum from parent-left from " << root->data << endl;
        vector<vector<int>> leftPaths = pathSum(root->left, sum, targetSum);
        for (vector<int> leftPath : leftPaths) {
            // Include the parent
            leftPath.insert(leftPath.begin(), root->data);
            paths.push_back(leftPath);
        }
    }
    if (root->right) {
        cout << "Calling path sum from parent-right from " << root->data << endl;
        vector<vector<int>> rightPaths = pathSum(root->right, sum, targetSum);
        for (vector<int> rightPath : rightPaths) {
            // Include the parent
            rightPath.insert(rightPath.begin(), root->data);
            paths.push_back(rightPath);
        }
    }

    // If sum is not found, start exploring fresh paths starting from this node.
    if (root->left) {
        cout << "Calling path sum from fresh-left from " << root->data << endl;
        vector<vector<int>> leftPaths = pathSum(root->left, 0, targetSum);
        for (vector<int> leftPath : leftPaths) {
            // No need to include parent here.
            paths.push_back(leftPath);
        }
    }

    if (root->right) {
        cout << "Calling path sum from fresh-right from " << root->data << endl;
        vector<vector<int>> rightPaths = pathSum(root->right, 0, targetSum);
        for (vector<int> rightPath : rightPaths) {
            // No need to include parent here.
            paths.push_back(rightPath);
        }
    }

    return paths;
}

int main() {

    /**
     *          10
     *         /   \
     *        5    -3
     *       / \     \
     *      3   2     11
     *     / \   \
     *    3  -2   1
     */
    // Node *root = new Node(10);
    // Node *n1 = new Node(5);
    // Node *n2 = new Node(-3);
    // Node *n3 = new Node(3);
    // Node *n4 = new Node(2);
    // Node *n5 = new Node(11);
    // Node *n6 = new Node(3);
    // Node *n7 = new Node(-2);
    // Node *n8 = new Node(1);

    // root->left = n1;
    // root->right = n2;

    // n1->left = n3;
    // n1->right = n4;

    // n2->right = n5;

    // n3->left = n6;
    // n3->right = n7;

    // n4->right = n8;

    // printVectorOfVectors(pathSum(root, 0, 8));

    // delete n8;
    // delete n7;
    // delete n6;
    // delete n5;
    // delete n4;
    // delete n3;
    // delete n2;
    // delete n1;
    // delete root;

    /**
     *          5
     *         / \
     *        4   8
     *       /   / \
     *      11  13  4
     *     / \     / \
     *    7   2   5   1
     */
    // Node *root = new Node(5);
    // Node *n1 = new Node(4);
    // Node *n2 = new Node(8);
    // Node *n3 = new Node(11);
    // Node *n4 = new Node(13);
    // Node *n5 = new Node(4);
    // Node *n6 = new Node(7);
    // Node *n7 = new Node(2);
    // Node *n8 = new Node(5);
    // Node *n9 = new Node(1);

    // // Set up the tree structure
    // root->left = n1;
    // root->right = n2;

    // n1->left = n3;
    // // n1->right is null

    // n2->left = n4;
    // n2->right = n5;

    // n3->left = n6;
    // n3->right = n7;

    // // n4->left is null
    // // n4->right is null

    // n5->left = n8;
    // n5->right = n9;

    // printVectorOfVectors(pathSum(root, 0, 22));

    // // Clean up dynamically allocated nodes
    // delete n9;
    // delete n8;
    // delete n7;
    // delete n6;
    // delete n5;
    // delete n4;
    // delete n3;
    // delete n2;
    // delete n1;
    // delete root;

    /**
     *     1
     *      \
     *       2
     *        \
     *         3
     *          \
     *           4
     *            \
     *             5
     */
    Node *root = new Node(1);
    Node *n1 = new Node(2);
    Node *n2 = new Node(3);
    Node *n3 = new Node(4);
    Node *n4 = new Node(5);

    // Set up the tree structure (right-skewed tree)
    root->right = n1;
    // root->left is null

    n1->right = n2;
    // n1->left is null

    n2->right = n3;
    // n2->left is null

    n3->right = n4;
    // n3->left is null

    // n4->left and n4->right are both null

    printVectorOfVectors(pathSum(root, 0, 3));

    // Clean up dynamically allocated nodes
    delete n4;
    delete n3;
    delete n2;
    delete n1;
    delete root;
}