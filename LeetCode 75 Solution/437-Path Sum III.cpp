/**
 * @brief Path Sum III
 * @ref https://leetcode.com/problems/path-sum-iii
 *
 * ## Describe the problem in your own words.
 * @date 25 December 2025
 * 1. The problem states to return an integer. This integer represents total no. of paths that add up to the target.
 * 2. The twist here is that these path can start from any node, not just the root.
 * 3. This makes the traversal logic a bit different than the regular recursion traversal.
 * 4. e.g. The following tree has 3 paths, all of which do not start from root, that add upto targetSum i.e. 8
 *      - [5, 3]
 *      - [5, 2, 1]
 *      - [-3, 11]
 *          10
 *         /   \
 *        5    -3
 *       / \     \
 *      3   2     11
 *     / \   \
 *    3  -2   1
 *
 * ## What approach solved the problem?
 * @date 25 December 2025
 * 1. My first solution was way too expensive. I made a list of all paths & then filtered if it summed up to targetSum.
 * 2. My second solution did not work. I was traversing the tree using the left/right recursion logic & keeping track of
 *    the targetSum on-the-fly using `sumUntilNow`. If `sumUntilNow` < targetSum, I kept traversing & if the sum of
 *    nodes went beyond the targetSum, I was resetting the `sumUntilNow` & starting a new recursion from that node. The
 *    problem was I assumed all nodes have +ve values. Even if the `sumUntilNow` > targetSum, it was possible that
 *    follow up nodes could have -ve values & thereby resulting in targetSum. Furthermore, there were way to many
 *    recursion calls happening.
 * 3. The final solution, given by Claude, involved rethinking the recursion logic all together. The regular left/right
 *    recursion was purely for traversing paths from a `given root to all its children`, lets call it 'Explorer'. It
 *    can't be used to start a new traversing route from any its children. e.g. The above tree would result in
 *    [10, 5, 3, 3], [10, 5, 3, -2], [10, 5, 2, 1]... & not [5, 3, 3], etc. Furthermore, it is the job of the caller
 *    (Manager) to give each new node a chance to traverse its own children. This separation of concerns b/w Manager &
 *    Explorer ensures each path is counted exactly once without duplicates.
 */
#include "../DS Implementation/Tree-Utils.cpp"
#include "../Utils.cpp"
#include <iostream>

using namespace std;

/**
 * Explorer: Explores paths originating from root.
 */
int countPathFromNode(TreeNode *root, int sumUntilNow, int targetSum) {
  if (root == nullptr) {
    return 0;
  } else {
    cout << "\n\nVisiting " << root->val << " sumUntilNow: " << sumUntilNow << " targetSum: " << targetSum << endl;

    int pathCount = 0;
    sumUntilNow += root->val;

    pathCount = (sumUntilNow == targetSum) ? 1 : 0;
    pathCount += countPathFromNode(root->left, sumUntilNow, targetSum);
    pathCount += countPathFromNode(root->right, sumUntilNow, targetSum);

    return pathCount;
  }
}

/**
 * Manager: Recursively visits each node & starts exploring new paths from each of those nodes.
 */
int pathSum(TreeNode *root, int targetSum) {
  if (root == nullptr) {
    return 0;
  } else {
    // Explore paths originating from root.
    int pathCountOnCurrent = countPathFromNode(root, 0, targetSum);

    // Recursively visit left node.
    int pathCountOnLeft = pathSum(root->left, targetSum);

    // Recursively visit right node.
    int pathCountOnRight = pathSum(root->right, targetSum);

    return pathCountOnCurrent + pathCountOnLeft + pathCountOnRight;
  }
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
  // TreeNode *root = new TreeNode(10);
  // TreeNode *n1 = new TreeNode(5);
  // TreeNode *n2 = new TreeNode(-3);
  // TreeNode *n3 = new TreeNode(3);
  // TreeNode *n4 = new TreeNode(2);
  // TreeNode *n5 = new TreeNode(11);
  // TreeNode *n6 = new TreeNode(3);
  // TreeNode *n7 = new TreeNode(-2);
  // TreeNode *n8 = new TreeNode(1);

  // root->left = n1;
  // root->right = n2;

  // n1->left = n3;
  // n1->right = n4;

  // n2->right = n5;

  // n3->left = n6;
  // n3->right = n7;

  // n4->right = n8;

  // cout << pathSum(root, 3) << endl;

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
  // TreeNode *root = new TreeNode(5);
  // TreeNode *n1 = new TreeNode(4);
  // TreeNode *n2 = new TreeNode(8);
  // TreeNode *n3 = new TreeNode(11);
  // TreeNode *n4 = new TreeNode(13);
  // TreeNode *n5 = new TreeNode(4);
  // TreeNode *n6 = new TreeNode(7);
  // TreeNode *n7 = new TreeNode(2);
  // TreeNode *n8 = new TreeNode(5);
  // TreeNode *n9 = new TreeNode(1);

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
  TreeNode *root = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(3);
  TreeNode *n3 = new TreeNode(4);
  TreeNode *n4 = new TreeNode(5);

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

  cout << pathSum(root, 3) << endl;

  // Clean up dynamically allocated nodes
  delete n4;
  delete n3;
  delete n2;
  delete n1;
  delete root;
}

/**
 * Second solution. Did not work.
 */
int tranverseForSum_Wrong1(TreeNode *root, int sumUntilNow, int targetSum) {
  if (root == nullptr) {
    return 0;
  } else {
    cout << "\n\nVisiting " << root->val << " sumUntilNow: " << sumUntilNow << " targetSum: " << targetSum << endl;
    int pathSumCount = 0;
    int sumUntilCurrentTreeNode = sumUntilNow + root->val;

    if (sumUntilCurrentTreeNode == targetSum || root->val == targetSum) {
      pathSumCount = 1;
    }

    if (root->left) {
      if (sumUntilCurrentTreeNode > targetSum) {
        pathSumCount += tranverseForSum_Wrong1(root->left, 0, targetSum);
      } else {
        pathSumCount += tranverseForSum_Wrong1(root->left, sumUntilCurrentTreeNode, targetSum);
      }
    }

    if (root->right) {
      if (sumUntilCurrentTreeNode > targetSum) {
        pathSumCount += tranverseForSum_Wrong1(root->right, 0, targetSum);
      } else {
        pathSumCount += tranverseForSum_Wrong1(root->right, sumUntilCurrentTreeNode, targetSum);
      }
    }

    return pathSumCount;
  }
}

int pathSum_Wrong1(TreeNode *root, int targetSum) { return tranverseForSum_Wrong1(root, 0, targetSum); }

/**
 * First solution. Inefficient
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
vector<vector<int>> traceAllPaths(TreeNode *root, int sumUntilNow, int targetSum) {
  cout << "\n\npathSum called: TreeNode: " << root->val << " sumUntilNow: " << sumUntilNow
       << " targetSum: " << targetSum << endl;
  vector<vector<int>> paths;

  if (!root)
    return paths;

  int sum = root->val + sumUntilNow;

  // Sum found. Record the node.
  if (targetSum == sum) {
    cout << "Recording " << root->val << endl;
    paths.push_back({root->val});
  }

  // If sum is not found, continue exploring existing path which started from the parent.
  if (root->left) {
    cout << "Calling path sum on left of " << root->val << endl;
    vector<vector<int>> leftPaths = traceAllPaths(root->left, sum, targetSum);
    for (vector<int> leftPath : leftPaths) {
      // Include the parent in the path
      leftPath.insert(leftPath.begin(), root->val);

      // Push the path
      paths.push_back(leftPath);
    }
  }
  if (root->right) {
    cout << "Calling path sum on right of " << root->val << endl;
    vector<vector<int>> rightPaths = traceAllPaths(root->right, sum, targetSum);
    for (vector<int> rightPath : rightPaths) {
      // Include the parent in the path.
      rightPath.insert(rightPath.begin(), root->val);

      // Push the path
      paths.push_back(rightPath);
    }
  }

  // If sum is not found, start exploring fresh paths starting from this node.
  if (root->left) {
    cout << "Calling path sum from fresh-left from " << root->val << endl;
    vector<vector<int>> leftPaths = traceAllPaths(root->left, 0, targetSum);
    for (vector<int> leftPath : leftPaths) {
      // No need to include parent here.
      paths.push_back(leftPath);
    }
  }

  if (root->right) {
    cout << "Calling path sum from fresh-right from " << root->val << endl;
    vector<vector<int>> rightPaths = traceAllPaths(root->right, 0, targetSum);
    for (vector<int> rightPath : rightPaths) {
      // No need to include parent here.
      paths.push_back(rightPath);
    }
  }

  return paths;
}

int pathSum_Wrong(TreeNode *root, int targetSum) {
  int sumUntilNow = 0;
  return traceAllPaths(root, sumUntilNow, targetSum).size();
}