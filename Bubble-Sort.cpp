/**
 * @author Sagar Sutar 
 * @date 2025-07-11
 * @brief Bubble Sort
 * 
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

    // Each outer iterater is termed as "pass" i.e. 0th pass, 1st pass, 2nd pass, etc.
    int outerIterationCount = values.size();
    for (int outerIdx = 0; outerIdx < outerIterationCount; outerIdx++)
    {
        // In each pass, the greatest number would be pushed to the last index.
        // Apart from the last index, rest of the array is unsorted.
        // The inner loop would only iterate the "unsorted" part of the array.
        int innerIterationCount = values.size() - outerIdx;

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