/**
 * @brief Tree visualization and debugging utilities for binary tree algorithms.
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * @brief Data structure representing a node of the tree.
 */
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    int height;
    TreeNode() : val(0), left(nullptr), right(nullptr), height(1) {};
    TreeNode(int value) : val(value), left(nullptr), right(nullptr), height(1) {};
};

/**
 * @brief Ignore this. Its a helper function for `void printTree()`.
 */
int treeHeight(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + std::max(treeHeight(root->left), treeHeight(root->right));
}

/**
 * @brief Ignore this. Its a helper function for `void printTree()`.
 */
void printLevel(const std::vector<TreeNode *> &nodes, int level, int maxLevel)
{
    if (nodes.empty() || std::all_of(nodes.begin(), nodes.end(), [](TreeNode *n)
                                     { return n == nullptr; }))
    {
        return;
    }

    int floor = maxLevel - level;
    int edgeLines = (int)std::pow(2, std::max(floor - 1, 0));
    int firstSpaces = (int)std::pow(2, floor) - 1;
    int betweenSpaces = (int)std::pow(2, floor + 1) - 1;

    // Print node data with spaces
    for (int i = 0; i < nodes.size(); ++i)
    {
        if (i == 0)
            std::cout << std::string(firstSpaces, ' ');
        else
            std::cout << std::string(betweenSpaces, ' ');

        if (nodes[i])
            std::cout << nodes[i]->val;
        else
            std::cout << ' ';
    }
    std::cout << std::endl;

    // Print branches '/' and '\'
    for (int i = 1; i <= edgeLines; ++i)
    {
        for (int j = 0; j < nodes.size(); ++j)
        {
            int count = (j == 0) ? firstSpaces - i : betweenSpaces - 2 * i;
            std::cout << std::string(count > 0 ? count : 0, ' ');

            if (nodes[j] == nullptr)
            {
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
    std::vector<TreeNode *> newNodes;
    for (auto node : nodes)
    {
        if (node)
        {
            newNodes.push_back(node->left);
            newNodes.push_back(node->right);
        }
        else
        {
            newNodes.push_back(nullptr);
            newNodes.push_back(nullptr);
        }
    }

    printLevel(newNodes, level + 1, maxLevel);
}

/**
 * @brief Prints a tree starting from the given root.
 * @ref This function is generated via Perplexity.
 */
void printTree(TreeNode *root)
{
    int maxLevel = treeHeight(root);
    printLevel({root}, 1, maxLevel);
}

/**
 * @brief Returns a string form of node data <Left TreeNode Data, Current TreeNode Data, Right TreeNode Data>
 */
string getNodeStr(const TreeNode *node)
{
    if (node == nullptr)
    {
        return "null null null";
    }
    string leftStr = node->left ? to_string(node->left->val) : "null";
    string rightStr = node->right ? to_string(node->right->val) : "null";
    return leftStr + " " + to_string(node->val) + " " + rightStr;
}

string vectorNodeToString(vector<TreeNode *> nodes)
{
    stringstream vecStr;
    vecStr << "{";
    for (int i = 0; i < nodes.size(); ++i)
    {
        vecStr << nodes[i]->val;
        if (i < nodes.size() - 1)
            vecStr << ", ";
    }
    vecStr << "}";
    return vecStr.str();
}