/**
 * @brief Search Insert Position
 * @ref https://leetcode.com/problems/search-insert-position/
 *
 * ## Describe the problem in your own words.
 * @date 26th December 2025
 * 1. The problem states to return an integer. This integer represents an index of a targetNum that needs to be found in
 *    the input vector. If the target is not found, then it's supposed position should be returned.
 * 2. e.g. targetNum=5, [1,2,3,4,6,7,8] -> the targetNum does not exists, but it's supposed position is on index no. 4.
 *
 * ## What approach solved the problem?
 * @date 26th December 2025
 * 1. The solution involves dividing the vector in left/right halves & visit each half recursively.
 * 2. Once the middle element is reached, we check if the target is is middle.
 * 3. If so, we return the middleIdx, if not, there targetNum is either or left or right of the middleIdx because the
 *    input vector is sorted.
 */
#include "../Utils.cpp"
#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target) {
  if (nums.size() == 0) {
    return 0;
  }
  int middleIdx = nums.size() / 2;

  if (nums.size() == 1 && target != nums.at(0)) {
    // If only 1 item is in the vector, & it does not match the target,
    // then the target can either be inserted to the left or the right.
    if (target < nums.at(middleIdx)) {
      //  If target is inserted to the left of vec, then its index is 0.
      return 0;
    } else {
      // If target is inserted to the right of vec, then its index is 1.
      return 1;
    }
  } else if (nums.at(middleIdx) == target) {
    // Return index if target is found in middle.
    return middleIdx;
  } else if (target > nums.at(middleIdx)) {
    // Go to the right.
    vector<int> rightVec(nums.begin() + middleIdx, nums.end());

    // Whenever recursing to right, the previous index needs to be maintained because rightVec starts from middleIdx
    // & it recursively led to the current recursion call.
    return middleIdx + searchInsert(rightVec, target);
  } else {
    // Go to the left
    vector<int> leftVec(nums.begin(), nums.begin() + middleIdx);

    // No need to maintain previous index when going to left because it leftVec starts from 0.
    return searchInsert(leftVec, target);
  }
}

// int main() {
//   vector<int> vec = {1, 3, 5, 6};
//   int target = 7;
//   cout << vectorIntToString(vec) << " target: " << target << " would exist on index: " << searchInsert(vec, target)
//        << endl;
//   return 0;
// }