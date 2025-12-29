/**
 * @brief Increasing Triplet Subsequence
 * @ref https://leetcode.com/problems/increasing-triplet-subsequence
 *
 * ## Describe the problem in your own words.
 * @date 29 December 2025
 * 1. The problem states to return a boolean. This boolean value represents the existance of a triplet such that
 *   i < j < k & nums[i] < nums[j] < nums[k]
 *
 * ## What approach solved the problem?
 * @date 29 December 2025
 * 1. My first solution is inefficient with O(n)^3 complexity.
 * 2. The efficient solution
 *
 */
// #include "../Utils.cpp"
#include "./35 - Search Insert Position.cpp"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool increasingTriplet(vector<int> &nums) {
  if (nums.size() < 1 || nums.size() > 500000) {
    return false;
  } else {
    /**
     * firstSmallest: The smallest value encountered so far.
     * secondSmallest: A value greater than the `firstSmallest` encountered in forward iteration. It isn't necessarily
     *                 global 2nd smallest.
     * These are relative variable that form valid increasing pair as per the problem statement.
     */
    int firstSmallestNum = INT32_MAX;
    int secondSmallestNum = INT32_MAX;

    for (int i = 0; i < nums.size(); i++) {
      if (nums.at(i) <= firstSmallestNum) {
        cout << "First smallest number found " << i << "\t" << nums.at(i) << endl;
        firstSmallestNum = nums.at(i);
      } else if (nums.at(i) <= secondSmallestNum) {
        cout << "Second smallest number found " << i << "\t" << nums.at(i) << endl;
        secondSmallestNum = nums.at(i);
      } else {
        return true;
      }
    }

    return false;
  }
}

int main() {
  // vector<int> nums = {1, 2, 3, 4, 5};
  // vector<int> nums = {20, 100, 10, 12, 5, 13};
  vector<int> nums = {1, 5, 0, 4, 1, 2, 3};
  bool tripletsFound = increasingTriplet(nums);
  cout << "Triplets " << (tripletsFound ? "found for " : "not found for ") << vectorIntToString(nums) << endl;
  return 0;
}

/**
 * @brief This isn't the most optimal solution (n.log(n)) but its pretty cool given it utilizes existing LC problem. I
 * found it in LC Solution tab.
 * https://leetcode.com/problems/increasing-triplet-subsequence/solutions/6635446/master-the-two-pointer-pattern-to-detect-gsbw/comments/3276175/
 *
 */
bool increasingTriplet__inefficient(vector<int> &nums) {
  if (nums.size() < 1 || nums.size() > 500000) {
    return false;
  } else {
    // Resultant vector that would contain sorted values such that triplets[i] < triplets[j] < triplets[k]
    vector<int> triplets;

    for (int n : nums) {
      // Find the index where `n` should be inserted to maintain sorted order in triplets.
      int idx = searchInsert(triplets, n);

      // Build the sorted triplets vector.
      if (idx >= triplets.size()) {
        // If index is beyond the triplet size, insert it at the end.
        triplets.push_back(n);
      } else {
        // If index is within the triplet size, it means `n` is smaller than existing `triplets.at(idx)`.
        // Replace it to maintain the sorted order.
        triplets.at(idx) = n;
      }
      if (triplets.size() == 3) {
        return true;
      }
    }

    return false;
  }
}

/**
 * @brief This isn't the most optimal solution: O(n)^3
 */
bool increastingTriplet_inefficient(vector<int> &nums) {
  if (nums.size() < 1 || nums.size() > 500000) {
    return false;
  }
  for (int i = 0; i < nums.size() - 2; i++) {
    for (int j = i + 1; j < nums.size() - 1; j++) {
      if (i < j && nums.at(i) < nums.at(j)) {
        cout << "Found2 " << i << "\t" << j << endl;
        for (int k = j + 1; k < nums.size(); k++) {
          if (j < k && nums.at(j) < nums.at(k)) {
            cout << "Found triplets" << endl;
            cout << "i:" << i << "\tj: " << j << "\tk: " << k << endl;
            cout << "nums.at(i): " << nums.at(i) << " \tnums.at(j): " << nums.at(j) << "\tnums.at(k): " << nums.at(k)
                 << endl;
            return true;
          }
        }
      }
    }
  }
}
