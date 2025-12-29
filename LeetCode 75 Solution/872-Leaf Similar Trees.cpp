/**
 * @brief Leaf-Similar Trees
 * @ref https://leetcode.com/problems/leaf-similar-trees/
 *
 * ## Describe the problem in your own words.
 * @date 23 December 2025
 * 1. The problem states to return a boolean value. The boolean value represents if the two trees have same leaf
 *    sequence.
 * 2. e.g. The following two trees are "leaf-similar" as both have same leaf sequence i.e. [2, 4, 7]
 *
 *        5                    9
 *      /   \                /   \
 *     3     6              4     7
 *    / \     \            / \
 *   2   4     7          2   4
 *
 * ## What approach solved the problem?
 * @date 23 December 2025
 * 1. The solution involves iterating the left/right subtree, finding the leaf-node & adding it to a list.
 * 2. This list is generated for both the trees & final result is found accordingly.
 */
#include "../DS Implementation/Tree-Utils.cpp"
#include <iostream>

using namespace std;

/**
 * Returns a list of all the leaf nodes data.
 */
vector<int> getLeafNodes(TreeNode *root) {
  vector<int> leafNodes = {};
  if (root == nullptr) {
    return leafNodes;
  }

  if (root->left == nullptr && root->right == nullptr) {
    // Leaf node is reached
    leafNodes.push_back(root->val);
  }

  if (root->left != nullptr) {
    // Traverse the left subtree.
    vector<int> leftNodes = getLeafNodes(root->left);
    leafNodes.insert(leafNodes.end(), leftNodes.begin(), leftNodes.end());
  }

  if (root->right != nullptr) {
    // Traverse the right subtree.
    vector<int> rightNodes = getLeafNodes(root->right);
    leafNodes.insert(leafNodes.end(), rightNodes.begin(), rightNodes.end());
  }

  return leafNodes;
}

bool leafSimilar(TreeNode *root1, TreeNode *root2) { return getLeafNodes(root1) == getLeafNodes(root2); }

int main() {
  /**
   *        5
   *      /   \
   *     3     6
   *    / \     \
   *   2   4     7
   */
  TreeNode *root1 = new TreeNode(5);
  TreeNode *n1 = new TreeNode(3);
  TreeNode *n2 = new TreeNode(6);
  TreeNode *n3 = new TreeNode(2);
  TreeNode *n4 = new TreeNode(4);
  TreeNode *n5 = new TreeNode(7);

  root1->left = n1;
  root1->right = n2;

  n1->left = n3;
  n1->right = n4;

  n2->right = n5;

  TreeNode *root2 = new TreeNode(9);
  TreeNode *p1 = new TreeNode(4);
  TreeNode *p2 = new TreeNode(7);
  TreeNode *p3 = new TreeNode(2);
  TreeNode *p4 = new TreeNode(4);

  root2->left = p1;
  root2->right = p2;

  p1->left = p3;
  p1->right = p4;

  cout << "Are leaf-similar: " << (leafSimilar(root1, root2) ? "true" : "false") << endl;

  delete p4;
  delete p3;
  delete p2;
  delete p1;
  delete root2;

  delete n5;
  delete n4;
  delete n3;
  delete n2;
  delete n1;
  delete root1;

  return 0;
}