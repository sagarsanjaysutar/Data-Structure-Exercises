/**
 * @brief Count Good Nodes in Binary Tree
 * @ref https://leetcode.com/problems/count-good-nodes-in-binary-tree
 *
 * ## Describe the problem in your own words.
 * @date 23 December 2025
 * 1. The problem states to return an integer. The integer represents no. of good nodes in a binary tree.
 * 2. A good node is the one whose value is greater or equal to it's ancestor nodes.
 * 3. e.g. In the below tree, only the following paths contains a good node.
 *      - Path: [3], Good TreeNode: 3
 *      - Path: [3, 1, 3], Good TreeNode: 3
 *      - Path: [3, 4], Good TreeNode: 4
 *      - Path: [3, 4, 5], Good TreeNode: 5
 *   Rest of the paths like, [3, 1] & [3, 4, 1] do not fit the criteria, thus in total there are 4 good nodes.
 *
 *         3
 *       /   \
 *      1      4
 *     /      /  \
 *    3      1    5
 *
 * ## What approach solved the problem?
 * @date 23 December 2025
 * 1. My first solution was an inefficient one where I would make a list of all traversable paths
 *    & then filter out the good nodes. This is very expensive.
 * 2. The optimal solution involves traversing the left/right subtree in a recursive way & while doing so
 *    count the occurance of the good nodes. A good node is verified using a maxVal variable that has occured
 *    so far on that path.
 *
 *
 **/
#include "../DS Implementation/Tree-Utils.cpp"
#include "../Utils.cpp"
#include <climits>
#include <iostream>

using namespace std;

/**
 * Optimal solution: By tracking the maxVal encountered, the good value can be found during the traversal
 * as opposed to non-optimal solution which does filtering post-traversal.
 *
 * @param maxVal Represents the maximum value encountered so far during traversing a path.
 */
int goodNodes(TreeNode *root, int maxVal) {
  int goodNodeCount = 0;

  if (root == nullptr) {
    return goodNodeCount;
  }

  // Check if the current node is good. If so, update the maxVal.
  bool isCurrentNodeGood = root->val >= maxVal;
  maxVal = isCurrentNodeGood ? root->val : maxVal;

  // Count the current node.
  goodNodeCount = goodNodeCount + (isCurrentNodeGood ? 1 : 0);

  if (root->left == nullptr && root->right == nullptr) {
    // Leaf node is found.
    return goodNodeCount;
  }

  if (root->left != nullptr) {
    // Count the nodes on left subtree.
    goodNodeCount = goodNodeCount + goodNodes(root->left, maxVal);
  }

  if (root->right != nullptr) {
    // Count the nodes on right subtree.
    goodNodeCount = goodNodeCount + goodNodes(root->right, maxVal);
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
  TreeNode *root = new TreeNode(3);
  TreeNode *n1 = new TreeNode(1);
  TreeNode *n2 = new TreeNode(4);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(1);
  TreeNode *n5 = new TreeNode(5);

  root->left = n1;
  root->right = n2;

  n1->left = n3;

  n2->left = n4;
  n2->right = n5;

  cout << "Good nodes: " << goodNodes(root, INT_MIN) << endl;

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
  // TreeNode *root = new TreeNode(3);
  // TreeNode *n1 = new TreeNode(3);
  // TreeNode *n2 = new TreeNode(4);
  // TreeNode *n3 = new TreeNode(2);

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

  return 0;
}

/**
 * Non-optimal solution:
 * 1. This function generates all the traversable paths and later filter it to find good nodes. This is expensive.
 */
vector<vector<int>> tracePath(TreeNode *root) {
  vector<vector<int>> paths;
  if (root == nullptr) {
    cout << "TreeNode is Nullptr." << endl;
    return paths;
  }

  // Record the path that ends at current node.
  paths.push_back({root->val});

  if (root->left == nullptr && root->right == nullptr) {
    // Record the path that ends at leaf node.
    return {{root->val}};
  }

  if (root->left != nullptr) {
    if (root->left->val < root->val) {
      return paths;
    }
    // Record the left path.
    vector<vector<int>> leftPaths = tracePath(root->left);
    for (auto leftPath : leftPaths) {
      leftPath.insert(leftPath.begin(), root->val); // Prepend root for readability.
      paths.push_back(leftPath);
    }
  }

  if (root->right != nullptr) {
    if (root->right->val < root->val) {
      return paths;
    }
    // Record the right path.
    vector<vector<int>> rightPaths = tracePath(root->right);
    for (auto rightPath : rightPaths) {
      rightPath.insert(rightPath.begin(), root->val); // Prepend root for readability.
      paths.push_back(rightPath);
    }
  }

  return paths;
}

int goodNode_Wrong(TreeNode *root) {

  vector<vector<int>> paths = tracePath(root);

  cout << "All paths " << endl;
  printVectorOfVectors(paths);

  // Filter good nodes
  for (int i = paths.size() - 1; i >= 0; --i) {
    bool remove = false;
    int lastIdx = paths[i].size() - 1;
    for (int idx = 0; idx < lastIdx; ++idx) {
      if (paths[i][idx] > paths[i][lastIdx]) {
        remove = true;
        break;
      }
    }
    if (remove) {
      paths.erase(paths.begin() + i);
    }
  }

  return paths.size();
}
