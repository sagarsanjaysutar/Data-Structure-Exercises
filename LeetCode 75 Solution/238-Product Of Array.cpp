/**
 * @brief Product of Array Except Self
 * @ref https://leetcode.com/problems/product-of-array-except-self
 * @ref https://www.youtube.com/watch?v=G9zKmhybKBM
 *
 * ## Describe the problem in your own words.
 * @date 27th December 2025
 * 1. The problem states to return an array. This array contains integers & its length is same as the input array.
 * 2. Each element in the resultant array is the product of all the other elements. This product at [i]th pos. does not
 *    include [i]th element.
 * 3. e.g. [1, 2, 3, 4] -> [ 2x3x4, 1x3x4, 1x2x4, 1x2x3 ] -> [24, 12, 8, 6]
 *
 * ## What approach solved the problem?
 * @date 27th December 2025
 * 1. My first solution did not work. I thought of multiplying [i]th element with rest of the elements & then dividing
 *    the product with [i]th element. This fits the creteria as [i]th element gets removed. But this approach fails
 *    where there is 0 in the array. Dividing with 0 is undefined.
 * 2. My second solution was the 2 loop method where I skip the current iteration & multiply rest of the elements,
 *    but this is not allowed.
 * 3. The final solution, taken from a YT video, involves "out-of-the-box" visualization. This visualization is
 *    very critical to understand the code.
 *    i. The following table needs to be visualizated where the rows are Original Vector, Left product, right product
 *       & result. Each column corresponds to the elements in the vector.
 *          +----------+-----+-----+-----+-----+
 *          | Vec      |     |     |     |     |
 *          +----------+-----+-----+-----+-----+
 *          | Left     |     |     |     |     |
 *          +----------+-----+-----+-----+-----+
 *          | Right    |     |     |     |     |
 *          +----------+-----+-----+-----+-----+
 *          | Result   |     |     |     |     |
 *          +----------+-----+-----+-----+-----+
 *    ii. For every [i]th pos. in left row, Look LEFT & calculate the total product by multiplying all elements to the
 *        left of [i] (excluding nums[i] itself).
 *   iii. For every [i]th pos. in right row, Look RIGHT & calculate the total product by multiplying all elements to the
 *        right of[i] (excluding nums[i] itself).
 *    iv. For every [i]th pos. in result row, calculate the total product by multiplying left[i] & right[i].
 *
 */
#include "../Utils.cpp"
#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
  int size = nums.size();
  vector<int> answers(size);
  vector<int> leftProducts(size);
  vector<int> rightProducts(size);

  //  Initialise as 1. It won't affect the o/p as num[i] * 1 = num[i].
  leftProducts[0] = 1;
  rightProducts[size - 1] = 1;

  // leftProducts[i] contains product of all elements to the left of [i].
  for (int idx = 1; idx < size; idx++) {
    leftProducts.at(idx) = nums.at(idx - 1) * leftProducts.at(idx - 1);
  }

  // rightProducts[i] contains product of all elements to the right to [i].
  for (int idx = size - 2; idx >= 0; idx--) {
    rightProducts.at(idx) = rightProducts.at(idx + 1) * nums.at(idx + 1);
  }

  for (int idx = 0; idx < size; idx++) {
    answers.at(idx) = leftProducts.at(idx) * rightProducts.at(idx);
  }

  return answers;
}

int main() {
  vector<int> nums = {1, 2, 3, 4};
  cout << "Original Vector: " << vectorIntToString(nums) << endl;
  cout << "Result Vector: " << vectorIntToString(productExceptSelf(nums)) << endl;
}