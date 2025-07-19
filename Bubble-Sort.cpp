/**
 * @brief Bubble Sort
 * @date 2025-07-11
 *
 * In this sorting algorithm, we keep pushing the greatest element to the last by going through the array in multiple passes.
 * After pushing the greatest element to the last, we won't be checking the last index in subsequent passes.
 * 1. The outer loop represents a pass.
 * 2. The inner loop pushes the great element to the last.
 * e.g. For 0th Pass, inner loop will go from 0 -> array.length() - 0,
 *      For 1th Pass, inner loop will go from 0 -> array.length() - 1,
 *      For 2nd Pass, inner loop will go from 0 -> array.length() - 2,
 *      etc.
 * @note Time complexity: O(n^2)
 *
 */
#include <iostream>
#include <vector>
#include "Utils.cpp"

using namespace std;

int main()
{
    vector<int> values = {10, 3, 20, 1, 78, 10, 23, 1};

    cout << "Unsorted array: " << vectorToString(values) << endl;

    // Iterate the array in each pass.
    for (int passIdx = 0; passIdx < values.size(); passIdx++)
    {
        // In each pass, the greatest number would be pushed to the last index.
        // Apart from the last index, rest of the array is unsorted.
        // Thus the inner loop would only iterate the "unsorted" part of the array.
        int innerIterationCount = values.size() - passIdx;

        // Finds the greatest number and pushes it to the last index.
        for (int innerIdx = 0; innerIdx < innerIterationCount - 1; innerIdx++)
        {
            if (values[innerIdx] > values[innerIdx + 1])
            {
                // Swapping
                int temp = values[innerIdx + 1];
                values[innerIdx + 1] = values[innerIdx];
                values[innerIdx] = temp;
            }
        }
    }

    cout << "Sorted array: " << vectorToString(values) << endl;

    return 0;
}