
/**
 * @brief Two Sum
 * @ref https://leetcode.com/problems/two-sum/solutions/6754748/video-step-by-step-easy-solution-by-niit-i4q6/
 *
 * ## What approach solved the problem?
 * @date 17th Decemeber 2025
 * 1. There is a clever logic for the O(n) solution which only become apparent when you plough your way through the inefficient O^2 logic.
 * 2. With O^2 logic, you would select one element using outer loop, match it with rest of the elements using inner loop & find
 *    out if that pair adds upto target.
 * 3. Rather than pairing method, you could substract a given element from target, & search the index of the result.
 * 4. e.g. {4, 20, 47, 20} target: 51. Using the outer loop, we start with 4 -> 51-4=47 -> What's the idx of 47 (which btw is guarented to exist as per question)?
 * 5. To find index of any element in a vector/array, the logic is always going to be O(n). So this result in O(n)^2.
 * 6. This is the key point. If we managed to get the 'finding' to O(1), then our entire logic becomes O(n).
 * 7. We can use hashmaps for O(1) lookup. Convert the array to hashMap with <value, idx> pair & write logic for Pt. 3 & 4.
 *
 * ## What was the first approach that popped in my head?
 * @date 17th December 2025
 * For O(n) solution, my first solution was to eliminate numbers greater than target because greater no.
 * won't add up to the target. But then I realised this solution only works for +ve integers. We also have to consider -ve int. as well.
 * Even two pointer solution was exhaustive as it checked all the elements against each other. There is no way to eliminate numbers.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "../Utils.cpp"
#include <unordered_map>

using namespace std;

/**
 * Efficient O(n) soln.
 */
vector<int> twoSum(vector<int> &nums, int target)
{
    // Create hash map for efficient lookup.
    unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); i++)
    {
        hashMap.insert({nums.at(i), i});
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int requiredNumber = target - nums.at(i);

        // find(...) return an iterator. An iterator "points" to a position.
        unordered_map<int, int>::iterator requiredNumberPosition = hashMap.find(requiredNumber);
        if (requiredNumberPosition != hashMap.end())
        {
            // Return the indices.
            return {i, requiredNumberPosition->second};
        }
    }

    return nums;
}

/**
 * Inefficient O^2 sol.
 */
vector<int> twoSums(vector<int> &nums, int target)
{

    for (int i = 0; i < nums.size(); i++)
    {
        int requiredNumber = target - nums.at(i);
        // find return an iterator. An iterator "points" to a position.
        vector<int>::iterator requiredNumberPosition = find(nums.begin(), nums.end(), requiredNumber);
        if (requiredNumberPosition != nums.end())
        {
            // To get the index, we substract iterators.
            int requiredNumberIdx = requiredNumberPosition - nums.begin();
            return {i, requiredNumberIdx};
        }
    }

    return nums;
}

int main()
{
    vector<int> vec = {4, 20, 47, 20, 48, 13, 18, 44};
    cout << "Original Vector: " << vectorIntToString(vec) << endl;
    cout << "Resultant Vector: " << vectorIntToString(twoSum(vec, 95)) << endl;
    return 0;
}