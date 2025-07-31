/**
 * Kids With the Greatest Number of Candies.cpp
 *
 * @ref https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description
 */
#include <iostream>
#include <vector>
#include "../Utils.cpp"

using namespace std;

/**
 * Optimal solution.
 * This is not mine. I got this from LeetCode's "Solutions" tab.
 */
vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    // Find out the child with maximum candies.
    int maxCandies = 0;
    for (int idx = 0; idx < candies.size(); idx++)
    {
        maxCandies =
            candies.at(idx) > maxCandies ? candies.at(idx) : maxCandies;
    }

    // Check if after giving extra candies to the child, does the child have
    // greatest number of candies.
    vector<bool> result = {};
    for (int idx = 0; idx < candies.size(); idx++)
    {
        bool hasGreatestCandies =
            (candies.at(idx) + extraCandies) >= maxCandies;
        result.push_back(hasGreatestCandies);
    }

    return result;
}

int main()
{
    // vector<int> candies = {2, 3, 5, 1, 3};
    // int extraCandies = 3;

    vector<int> candies = {4, 2, 1, 1, 2};
    int extraCandies = 1;

    // vector<int> candies = {12, 1, 12};
    // int extraCandies = 10;

    cout << "Candies: " << vectorToString(candies) << endl;
    cout << "Result: " << vectorToString3(kidsWithCandies(candies, extraCandies)) << endl;

    return 0;
}

/**
 * This was my first solution and it is non-optimal as after giving extra
 * candies to the child, I am checking if he has the greatest by comparing
 * with all the other child.
 *
 * I don't need to do this. I just has the child against the child with
 * maximum candies.
 */
// vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
//     // Represents a new "candies-vector" after giving each child all the
//     // candies.
//     vector<int> newCandies = {};

//     // Final result vector.
//     vector<bool> result = {};

//     // Give extra candies to each child.
//     for (int idx = 0; idx < candies.size(); idx++) {
//         newCandies.push_back(candies.at(idx) + extraCandies);
//     }

//     // Iterate the newCandies vector to check if the child has the greatest
//     // number of candies.
//     for (int newCandiesIdx = 0; newCandiesIdx < newCandies.size();
//          newCandiesIdx++) {
//         // Represent if the child in the current iteration has the greatest
//         // number of candies or not.
//         bool isGreatest = true;

//         // Determine if the child's new candies are greatest amongst all
//         // kids.
//         for (int candiesIdx = 0; candiesIdx < candies.size();
//              candiesIdx++) {
//             if (newCandies.at(newCandiesIdx) < candies.at(candiesIdx)) {
//                 isGreatest = false;
//                 break;
//             }
//         }

//         result.push_back(isGreatest);
//     }
//     return result;
// }