#include "../Data Structures/Utils.cpp"
#include <iostream>

using namespace std;

vector<Node *> getLeafNodes(Node *root) {
    cout << "Calling getLeafNodes " << endl;
    vector<Node *> leafNodes;
    if (root == nullptr) {
        return {};
    } else if (root->left == nullptr && root->right == nullptr) {
        // Leaf node is reached
        return {root};
    } else if (root->left != nullptr && root->right != nullptr) {
        vector<Node *> leftNodes = getLeafNodes(root->left);
        leafNodes.insert(leafNodes.end(), leftNodes.begin(), leftNodes.end());
        vector<Node *> rightNodes = getLeafNodes(root->right);
        leafNodes.insert(leafNodes.end(), rightNodes.begin(), rightNodes.end());
    } else if (root->left == nullptr) {
        vector<Node *> rightNodes = getLeafNodes(root->right);
        leafNodes.insert(leafNodes.end(), rightNodes.begin(), rightNodes.end());
    } else if (root->right == nullptr) {
        vector<Node *> leftNodes = getLeafNodes(root->left);
        leafNodes.insert(leafNodes.end(), leftNodes.begin(), leftNodes.end());
    }
    return leafNodes;
}

int main() {
    /**
     *        5
     *      /   \
     *     3     6
     *    / \     \
     *   2   4     7
     */
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

    vector<Node *> leafNodes = getLeafNodes(root);
    cout << "Leaf Nodes: " << getStringTreeFromVector(leafNodes) << endl;

    delete n5;
    delete n4;
    delete n3;
    delete n2;
    delete n1;
    delete root;

    return 0;
}