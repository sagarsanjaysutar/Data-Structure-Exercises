/**
 * @brief Quick Sort with middle pivot
 *
 * @date July 27th, 2025
 * FIGURED OUT THIS ALGORITHM.
 * The problem was my reArrangeVec function didn't guarantee that everything on left of pivot was lesser
 * & everything on the right of the pivot of greater. I had implied that as the vector would further get divided,
 * it would automatically sort itself.
 * Another issue was not handling the single-side swap edge case. (Read reArrangeVec description)
 *
 * @date July 22th, 2025
 * I've learnt that traditional QS algo works with only 1 array & mutates it with Low, high, mid values.
 * the traditional rearrangeVec "GUARANTEES" that pivot would be in correct position.
 * It returns that position which is further used.
 *
 * My problem: I added a pivot-ignoring logic in left & right quick sort calls ASSUMING that pivot is in
 * correct position so it does need to be passed to next recursion function.
 * But this caused issue with array size was 3.
 * - (1, 6, 3) did not work but (1, 6, 3, 0) worked
 * - THIS IS RESOLVED I HAVE REMOVED THIS.
 *
 * my rearrangeVec does not GUARANTEES the pivot would be in correct position.
 * - Unique numbers > 4 work but duplicate numbers at certain position like L, H, M will cause issues.
 * - The issue is entirely in the rearrangeVec function. It does not handle === condition properly.
 * THIS NEEDS TO BE FIXED. How can I GUARANTEE pivot is in right place?
 *
 * @date July 20th, 2025
 * I'm giving up on this again. Perplexity is confidently gives wrong solution.
 * When probed, it agrees but gives the flawed soln again. e.g. swap(vec.at(rightPtr), vec.at(pivotIdx)); outside the while loop.
 *
 * @date February 9th, 2024
 * Problem with this solution is when duplicate occur.
 * e.g. Sorting the sub arr of {51, 132, 349, 204, 426, 388, 462, 105, 324, 0} ->  {51, 132, 349, 204, 0}, the zero here never goes to the 0th position
 * Most the problems revolves around left & right comparision.
 * For now, I'm moving on.
 *
 * @ref https://www.algolist.net/Algorithms/Sorting/Quicksort
 * https://stackoverflow.com/questions/27886150/quick-sort-with-middle-element-as-pivot
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include "Utils.cpp"

using namespace std;

/**
 * Rearranges the vector across the pivotIdx.
 *
 * @return Returns an updated vector & updated pivotIdx (if it has changed)
 *
 * @brief Smaller elements are on the left of the pivotIdx & greater/equal elements are to the right of the pivotIdx.
 * It does so in the following way:
 * 1. Double sided swap: When a greater element is found on left & smaller element is found on right of the pivotIdx,
 *                       these both are swapped.
 * 2. Single sided swap: When a greater element is found on left but no smaller element is found on right of the pivotIdx.
 *                       When a lesser element is found on right but no greater element is found on left of the pivotIdx.
 *                       When the above two condition occur, the lesser or the greater element is swapped with the pivotIdx.
 */
pair<int, vector<int>> rearrangeVec(vector<int> vec, int pivotIdx)
{
    // Left pointer going from beginning of the vector till the rightPtr to find elements greater than the pivot.
    int leftPtr = 0;

    // Right pointer going from the end of the vector till the leftPtr to find elements lesser than the pivot.
    int rightPtr = vec.size() - 1;

    // The pivot value across which elements needs to be arranged.
    int pivotValue = vec.at(pivotIdx);

    // Indicates if a greater element is found on the left of the pivotIdx.
    bool leftSwap = false;

    // Indicates if a smaller element is found on the right of the pivotIdx.
    bool rightSwap = false;

    while (true)
    {

        if (leftPtr >= rightPtr)
        {
            // If leftPtr goes beyond rightPtr then break the loop & return the rearranged vector.
            return {pivotIdx, vec};
        }

        if (vec.at(leftPtr) >= pivotValue)
        {
            // If a greater element is found on the leftPtr, then update the flag.
            leftSwap = true;

            /**
             * Single sided swap
             *
             * If a greater element is found on the leftPtr & rightPtr has already reached the pivot,
             * it means there is no lesser element on the right to swap the greater element with.
             * Thus swap the greater element with the pivot.
             * */
            if (rightPtr == pivotIdx)
            {
                // Swap pivot with the leftPtr.
                swap(vec.at(pivotIdx), vec.at(leftPtr));

                // After swapping, the pivot is now at leftPtr.
                pivotIdx = leftPtr;

                // Reset the flag.
                leftSwap = false;
                rightSwap = false;
            }
        }
        else
        {
            // If a greater element is not found, then increment the pointer & goto next element.
            leftPtr++;
        }

        if (vec.at(rightPtr) < pivotValue)
        {
            // If a lesser element is found on rightPtr, then update the flag.
            rightSwap = true;

            /**
             * Single sided swap
             *
             * If a lesser element is found on rightPtr & the leftPtr has already reached pivotIdx,
             * it means there is no greater element on the left to swap the lesser element with.
             * Thus swap the lesser element with the pivot.
             */
            if (leftPtr == pivotIdx)
            {
                // Swap the pivot with the leftPtr.
                swap(vec.at(pivotIdx), vec.at(rightPtr));

                // After swapping, the pivot is now at rightPtr.
                pivotIdx = rightPtr;

                // Reset the flag.
                leftSwap = false;
                rightSwap = false;
            }
        }
        else
        {
            // If lesser element is not found, then decrement the pointer & goto preceding element.
            rightPtr--;
        }

        /**
         * Double side swap
         *
         * If a lesser element is found on left & greater element is found on right, then swap both of them.
         */
        if (leftSwap && rightSwap)
        {
            // Swap both elements.
            swap(vec.at(leftPtr), vec.at(rightPtr));

            // Reset the flag.
            leftSwap = false;
            rightSwap = false;
        }
    }
}

vector<int> quickSort(vector<int> vec)
{

    if (vec.size() <= 1)
    {
        return vec;
    }
    else
    {
        // Middle point as the pivot.
        int pivotIdx = (vec.size()) / 2;
        pair<int, vector<int>> res = rearrangeVec(vec, pivotIdx);

        // Update the pivot if is has changed.
        pivotIdx = res.first;
        vector<int> rearrangedVec = res.second;

        // Partition the vector across pivot point.
        vector<int> leftVec(quickSort(vector<int>(rearrangedVec.begin(), rearrangedVec.begin() + pivotIdx)));

        // pivotIdx + 1: It is implied that the pivot is in correct position after calling rearrangeVec.
        vector<int> rightVec(quickSort(vector<int>(rearrangedVec.begin() + pivotIdx + 1, rearrangedVec.end())));

        // Add the sorted pivotIdx to the result.
        leftVec.push_back(rearrangedVec[pivotIdx]);

        // Merge the two sorted vector
        leftVec.insert(leftVec.end(), rightVec.begin(), rightVec.end());
        return leftVec;
    }
}

int main()
{
    vector<int> vec = getRandomVector();
    cout << "Original Vector: " << vectorToString(vec) << endl;
    vector<int> sortedVec(quickSort(vec));
    cout << "Sorted Vector: " << vectorToString(sortedVec) << endl;
    return 0;
}
