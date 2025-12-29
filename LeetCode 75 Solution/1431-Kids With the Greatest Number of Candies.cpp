/**
 * @brief Kids With the Greatest Number of Candies.cpp
 * @ref https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description
 *
 * ## Describe the problem in your own words.
 * @date 16th December 2025
 * 1. The problem states to return an array. This array contains boolean values & the length of it is equal to
 *    the input array.
 * 2. Each element in the input array represents no. of candies a kid has.e.g. In `[2, 3, 5, 1, 3]`, 5 kids are present
 *    & 2nd kid has 3 candies.
 * 3. We distribute extra candies to each of the kids (`extraCandies`) & determine if that kid has the greatest no.
 *    of candies after receiving the extra candies.
 * 4. e.g. After givng 3 candies to each kid, the amended array becomes [5, 6, 8, 4, 6] which results in
 *    [true, true, true, false, true]. 0th element of amended array i.e 5 is greatest amongst all kids in input array.
 *
 * ## What approach solved the problem?
 * @date 16th December 2025
 * 1. The solution involves running two separate loops.
 * 2. First loop finds out the child with greatest no. of candies, lets call it X.
 * 3. Second loop gives each child the extra candies, lets call the resultant vector Y.
 * 4. Each element in Y is compared against X.
 * 5. If Y[i], even after having extra candies is not greater than X, then it's automically disqualified &
 *    the boolean array is created accordingly.
 */
#include "../Utils.cpp"
#include <iostream>
#include <vector>

using namespace std;

/**
 * Optimal solution.
 * This is not mine. I got this from LeetCode's "Solutions" tab.
 */
vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
  // Find out the child with maximum candies.
  int maxCandies = 0;
  for (int idx = 0; idx < candies.size(); idx++) {
    maxCandies = candies.at(idx) > maxCandies ? candies.at(idx) : maxCandies;
  }

  // Check if after giving extra candies to the child, does the child have
  // greatest number of candies.
  vector<bool> result = {};
  for (int idx = 0; idx < candies.size(); idx++) {
    bool hasGreatestCandies = (candies.at(idx) + extraCandies) >= maxCandies;
    result.push_back(hasGreatestCandies);
  }

  return result;
}

int main() {
  // vector<int> candies = {2, 3, 5, 1, 3};
  // int extraCandies = 3;

  vector<int> candies = {4, 2, 1, 1, 2};
  int extraCandies = 1;

  // vector<int> candies = {12, 1, 12};
  // int extraCandies = 10;

  cout << "Candies: " << vectorIntToString(candies) << endl;
  cout << "Result: " << vectorBoolToString(kidsWithCandies(candies, extraCandies)) << endl;

  return 0;
}

/**
 * This was my first solution and it is non-optimal.
 * I gave extra candies to all the children & after that I compared it against original array.
 * This approach requires using nested for-loops. I don't need to do this. Refer the optimal solution.
 */
vector<bool> kidsWithCandies_inefficient(vector<int> &candies, int extraCandies) {
  // Represents a new "candies-vector" after giving each child all the
  // candies.
  vector<int> newCandies = {};

  // Final result vector.
  vector<bool> result = {};

  // Give extra candies to each child.
  for (int idx = 0; idx < candies.size(); idx++) {
    newCandies.push_back(candies.at(idx) + extraCandies);
  }

  // Iterate the newCandies vector to check if the child has the greatest
  // number of candies.
  for (int newCandiesIdx = 0; newCandiesIdx < newCandies.size(); newCandiesIdx++) {
    // Represent if the child in the current iteration has the greatest
    // number of candies or not.
    bool isGreatest = true;

    // Determine if the child's new candies are greatest amongst all
    // kids.
    for (int candiesIdx = 0; candiesIdx < candies.size(); candiesIdx++) {
      if (newCandies.at(newCandiesIdx) < candies.at(candiesIdx)) {
        isGreatest = false;
        break;
      }
    }

    result.push_back(isGreatest);
  }
  return result;
}