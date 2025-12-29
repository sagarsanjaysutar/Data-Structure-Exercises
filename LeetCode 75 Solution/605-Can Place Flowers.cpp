/**
 * @brief Can Place Flowers
 * @ref https://leetcode.com/problems/can-place-flowers/description
 *
 * ## Describe the problem in your own words.
 * @date 16th December 2025
 * 1. The problem states to return a boolean value. This boolean value represents whether `n` no. of new flowers can be
 *    planted in a flowerbed.
 * 2. The flowerbed is represented using an array e.g. [1, 0, 0, 1, 0] where 0 means an empty plot & 1 means non-empty
 *    plot.
 * 3. The catch is we can't directly plant flowers in the empty plots. There is a condition. This condition states that
 *    a new plant can only be planted into an empty plot if the adjacent plots are empty as well.
 * 4. e.g. In [1,0,0,0,1], only 1 new plant can be planted at 2nd Index.
 *    e.g. In [1,0,0,1], no new plant can be planted. Both 1st & 2nd index don't have empty adjacent plots.
 *
 * ## What approach solved the problem?
 * @date 16th December 2025
 * 1. The solution involves iterating the flower bed array.
 * 2. Return true in all these edge case.: [0], [...,0,0], [0,0,...].
 * 3. Add check to see current, previous & next position for empty plot & return true accordingly.
 *
 */
#include "../Utils.cpp"
#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n) {
  int flowerbedSize = flowerbed.size();
  // Constraints
  if (flowerbedSize < 1 || flowerbedSize > 20000 || n < 0 || n > flowerbedSize) {
    return false;
  }

  // A counter that gets incremented when conditions are met & we can plant the flower.
  int newPlantCount = 0;

  int idx = 0;
  while (idx < flowerbedSize) {

    if (newPlantCount == n) {
      // We've met the condition. We can plant "n" nos. of flowers.
      return true;
    } else if (flowerbedSize == 1 && flowerbed.at(0) == 0) {
      // Edge case handling: If there is only 1 element i.e. {0}, then then we can plant the flower.
      newPlantCount++;

      // No need to iterate further as there is only 1 element.
      break;
    } else if (flowerbedSize >= 2 && (idx == flowerbedSize - 1) && flowerbed.at(idx) == 0 &&
               flowerbed.at(idx - 1) == 0) {
      // Edge case handling: Special check for last element that confirms {...0, 0} therefore we can plant the flower.
      newPlantCount++;

      // No need to iterate further as we've reached last element.
      break;
    } else if (flowerbedSize >= 2 && (idx == 0) && flowerbed.at(idx) == 0 && flowerbed.at(idx + 1) == 0) {
      // Edge case handling: Special check for first element that confirms {0, 0...} therefore we can plant the flower.
      newPlantCount++;

      // Jump 2 steps ahead as we can't plant in an adjacent position.
      idx = idx + 2;
    } else if (flowerbedSize >= 3 && (idx > 0) && flowerbed.at(idx) == 0 && flowerbed.at(idx - 1) == 0 &&
               flowerbed.at(idx + 1) == 0) {
      // Confirm {...0,0,0...} therefor we can plant the flower.
      newPlantCount++;

      // Jump 2 steps ahead as we can't plant in an adjacent position.
      idx = idx + 2;
    } else {
      // If all none of the condition are met, move to the next iteration.
      idx++;
    }
  }

  return n == newPlantCount;
}

int main() {
  // vector<int> flowerbed = {1, 0, 0, 0, 0, 1};
  // int n = 2;

  // vector<int> flowerbed = {1, 0, 0, 0, 1};
  // int n = 1;

  vector<int> flowerbed = {0, 1, 0};
  int n = 1;

  if (canPlaceFlowers(flowerbed, n))
    cout << "Can plant " << n << " plants in " << vectorIntToString(flowerbed) << endl;
  else
    cout << "Cannot plant " << n << " plants in " << vectorIntToString(flowerbed) << endl;

  return 0;
}