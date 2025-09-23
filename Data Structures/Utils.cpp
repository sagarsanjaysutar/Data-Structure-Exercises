#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {};
    Node(int value) : data(value), left(nullptr), right(nullptr) {};
};

// Helper function to compute the height of the tree
int treeHeight(Node *root) {
    if (!root)
        return 0;
    return 1 + std::max(treeHeight(root->left), treeHeight(root->right));
}

// Helper function to print levels.
void printLevel(const std::vector<Node *> &nodes, int level, int maxLevel) {
    if (nodes.empty() || std::all_of(nodes.begin(), nodes.end(), [](Node *n) { return n == nullptr; })) {
        return;
    }

    int floor = maxLevel - level;
    int edgeLines = (int)std::pow(2, std::max(floor - 1, 0));
    int firstSpaces = (int)std::pow(2, floor) - 1;
    int betweenSpaces = (int)std::pow(2, floor + 1) - 1;

    // Print node data with spaces
    for (int i = 0; i < nodes.size(); ++i) {
        if (i == 0)
            std::cout << std::string(firstSpaces, ' ');
        else
            std::cout << std::string(betweenSpaces, ' ');

        if (nodes[i])
            std::cout << nodes[i]->data;
        else
            std::cout << ' ';
    }
    std::cout << std::endl;

    // Print branches '/' and '\'
    for (int i = 1; i <= edgeLines; ++i) {
        for (int j = 0; j < nodes.size(); ++j) {
            int count = (j == 0) ? firstSpaces - i : betweenSpaces - 2 * i;
            std::cout << std::string(count > 0 ? count : 0, ' ');

            if (nodes[j] == nullptr) {
                std::cout << std::string(edgeLines * 2 + i + 1, ' ');
                continue;
            }

            if (nodes[j]->left)
                std::cout << '/';
            else
                std::cout << ' ';

            std::cout << std::string(i * 2 - 1, ' ');

            if (nodes[j]->right)
                std::cout << '\\';
            else
                std::cout << ' ';
        }
        std::cout << std::endl;
    }

    // Prepare next level nodes vector
    std::vector<Node *> newNodes;
    for (auto node : nodes) {
        if (node) {
            newNodes.push_back(node->left);
            newNodes.push_back(node->right);
        } else {
            newNodes.push_back(nullptr);
            newNodes.push_back(nullptr);
        }
    }

    printLevel(newNodes, level + 1, maxLevel);
}

// Main function that prints the tree.
void printTree(Node *root) {
    int maxLevel = treeHeight(root);
    printLevel({root}, 1, maxLevel);
}

/**
 * Prints the node data: Left Node Data, Current Node Data, Right Node Data
 */
string getNodeStr(const Node *node) {
    if (node == nullptr) {
        return "null null null";
    }
    string leftStr = node->left ? to_string(node->left->data) : "null";
    string rightStr = node->right ? to_string(node->right->data) : "null";
    return leftStr + " " + to_string(node->data) + " " + rightStr;
}