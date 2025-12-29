/**
 * @brief Two Sum
 * @ref https://leetcode.com/problems/two-sum/solutions/6754748/video-step-by-step-easy-solution-by-niit-i4q6/
 *
 * ## Describe the problem in your own words.
 * @date 17th December 2025
 * 1. The problem states to return an array. This array contains 2 indices. The elements that these indices points to
 *    add up a targetSum.
 *
 * ## What approach solved the problem?
 * @date 17th December 2025
 * 1. My first solution did not work. I thought of eliminating numbers greater than target because those won't add up to
 *    the target. But then I realised this solution only works for +ve integers. We also have to consider -ve int. There
 *    was no way to eliminate numbers.
 * 2. My second solution was inefficient. With O^2 complexitiy, it selected one element using outer loop, matched it
 *    with rest of the elements using inner loop & found out the pair that added upto target.
 * 3. The final solution, taken from LC Solution Tab, involves two clever techniques to find the answer. Using the
 *    outer-loop, it iterated each element in the array. 1st clever technique was to substract the current element from
 *    the targetSum. The result would be the 2nd number required to be found. 2nd clever technique was to convert the
 *    array into hashMap -> {<value0, idx0>, <value1, idx1> ...}. Using the hashMap, the second number would be found in
 *    O(1). Thus resulting in resultant pair. e.g. {4, 20, 47, 20} target: 51. Using the outer loop,
 *    we start with 4 -> 51 - 4 = 47 -> If 47 exists, what's it idx?
 */
#include "../Utils.cpp"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Efficient O(n) soln.
 */
vector<int> twoSum(vector<int> &nums, int target) {
  // Create hash map for efficient lookup.
  unordered_map<int, int> hashMap;
  for (int i = 0; i < nums.size(); i++) {
    hashMap.insert({nums.at(i), i});
  }

  for (int i = 0; i < nums.size(); i++) {
    int requiredNumber = target - nums.at(i);

    // find(...) return an iterator. An iterator "points" to a position.
    unordered_map<int, int>::iterator requiredNumberPosition = hashMap.find(requiredNumber);
    if (requiredNumberPosition != hashMap.end()) {
      // Return the indices.
      return {i, requiredNumberPosition->second};
    }
  }

  return nums;
}

int main() {
  vector<int> vec = {4, 20, 47, 20, 48, 13, 18, 44};
  cout << "Original Vector: " << vectorIntToString(vec) << endl;
  cout << "Resultant Vector: " << vectorIntToString(twoSum(vec, 95)) << endl;
  return 0;
}

/**
 * Inefficient O^2 sol.
 */
vector<int> twoSum_Wrong(vector<int> &nums, int target) {

  for (int i = 0; i < nums.size(); i++) {
    int requiredNumber = target - nums.at(i);
    // find return an iterator. An iterator "points" to a position.
    vector<int>::iterator requiredNumberPosition = find(nums.begin(), nums.end(), requiredNumber);
    if (requiredNumberPosition != nums.end()) {
      // To get the index, we substract iterators.
      int requiredNumberIdx = requiredNumberPosition - nums.begin();
      return {i, requiredNumberIdx};
    }
  }

  return nums;
}
