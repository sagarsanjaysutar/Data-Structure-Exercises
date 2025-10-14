/**
 * @brief QuickSort: Divide & Conquer.
 * 1. Select a pivot point.
 * 2. Rearrange vec such that smaller elements are on left of pivot & greater ones are on right.
 * 3. Divide the rearranged vec. from the pivot point recursively.
 * 4. Merge the result two vec. & return.
 *
 * @note The rearrange part isn't the most optimal as it makes the solution O(n^2)
 * @ref https://www.programiz.com/dsa/quick-sort
 */

#include "Utils.cpp"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int>> rearrangeVec(vector<int> vec) {

    // Right most element is the pivot.
    int pivotIdx = vec.size() - 1;

    int idx = 0;

    // Place all the smaller elements to the left of the pivot & greater ones to the right.
    while (idx < pivotIdx) {

        // Condition: If maxVal is found, push it to the end.
        // Note: This is a non-optimal solution because of the 2 loops.
        if (vec.at(idx) >= vec.at(pivotIdx)) {
            int maxVal = vec.at(idx);

            // Place the maxVal at the end of vector & shift all elements towards left by 1.
            for (int i = idx; i < vec.size() - 1; i++) {
                vec.at(i) = vec.at(i + 1);
            }
            vec.at(vec.size() - 1) = maxVal;

            // Since maxVal is moved to the end, pivot is shifted by -1
            pivotIdx--;
        }

        // Check if the mutated vector follows the Condition
        if (vec.at(idx) < vec.at(pivotIdx)) {
            idx++;
        }
    }

    return {{pivotIdx, vec}};
}

vector<int> quickSort(vector<int> vec) {
    if (vec.size() <= 1) {
        return vec;
    }

    // Rearrange the vectorr
    map<int, vector<int>> res = rearrangeVec(vec);
    int pivotIdx = res.begin()->first;
    vector<int> rearrangedVec = res.begin()->second;

    // Recursively divide the vector from the pivot point
    vector<int> leftVec(quickSort(vector<int>(rearrangedVec.begin(), rearrangedVec.begin() + pivotIdx)));
    // pivotIdx + 1: It is implied that the pivot is in correct position after calling rearrangeVec.
    vector<int> rightVec(quickSort(vector<int>(rearrangedVec.begin() + pivotIdx + 1, rearrangedVec.end())));

    // Add the sorted pivotIdx to the result.
    leftVec.push_back(rearrangedVec.at(pivotIdx));

    // Merge the two sorted vector
    leftVec.insert(leftVec.end(), rightVec.begin(), rightVec.end());

    return leftVec;
}

int main() {
    vector<int> vec = getRandomVector();
    cout << "Original Vector: " << vectorIntToString(vec) << endl;
    vector<int> sortedVec(quickSort(vec));
    cout << "Sorted Vector: " << vectorIntToString(sortedVec) << endl;
    return 0;
}