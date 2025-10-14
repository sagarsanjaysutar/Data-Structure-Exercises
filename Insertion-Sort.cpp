/**
 * @brief Insertion Sort
 *
 * In this algorithm, an element is inserted in its "correct position" amongst the left-sorted portion of the array.
 *
 * 1. The outer loop represents a pass.
 * 2. The inner loop works in a reverse way. It iterates from i & goes till 0.
 *    If a smaller element is found while iterating, then the array is right-shifted
 *    & the smaller element is added to the "correct position".
 *    This "correct position" is calculated using a clever logic.
 *
 * @note Time Complexity: O(n^2)
 * @note To understand this algorithm, one needs to know about right shifting an array using a reverse loop.
 *       It's a bit un intuitive as left-shifting using forward loop is more intuitive.
 */
#include "Utils.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> intVec = {8, 7, 6, 5, 4, 3, 2, 1, 0};

    cout << "Original Vector: " << vectorIntToString(intVec) << endl;

    // Start from 1st idx as 0th is considered sorted.
    for (int i = 1; i < intVec.size(); i++) {
        // Value that needs to be compared.
        int value = intVec.at(i);

        // This needs to be initialized outside inner loop.
        // It helps in finding the "correct position" of the "value"
        int j = i;

        // If "value" is smaller than the preceding element then,
        //  - we right-shift all elements
        //  - place the "value" in the "correct position".
        for (j; j > 0 && intVec.at(j - 1) > value; j--) {
            intVec.at(j) = intVec.at(j - 1);
        }

        // Once the inner loop exits, j represents the "correct position" of "value".
        intVec.at(j) = value;
    }

    cout << "Sorted Vector: " << vectorIntToString(intVec) << endl;
}

/**
 * This code is not needed but helps in understanding some core insertion sort logic.
 *
    // Left-Shifting logic
    // for (int i = 0; i < intVec.size() - 1; i++)
    // {
    //     intVec.at(i) = intVec.at(i + 1);
    //     cout << "Shifted Array at " << i << " index: \t" << vectorIntToString(intVec) << endl;
    // }
    // return 0;

    // Right Shifting logic
    // for (int i = intVec.size() - 1; i > 0; --i)
    // {
    //     intVec.at(i) = intVec.at(i - 1);
    //     cout << "Shifted Array at " << i << " index: \t" << vectorIntToString(intVec) << endl;
    // }
    // return 0;

    // cout << "Shifted Array: \t\t" << vectorToStering(intVec) << endl;
 */