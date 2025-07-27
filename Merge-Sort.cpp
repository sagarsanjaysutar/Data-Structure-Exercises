/**
 * @brief Merge Sort
 * 
 * In this algorithm, we recursively divide the array in two halves, sort those half & merge the sorted halves.
 * 
 * @note Time complexity: n log(n): mergeSort(...) works in "log(n)" as it divides the input &
 * merge(...) works in "n" as it has single loop.
 *
 * @ref https://www.programiz.com/dsa/merge-sort
 */

#include <iostream>
#include <vector>
#include "Utils.cpp"

using namespace std;

/**
 * @brief Sorts & merges two vector.
 * @ref Refer the "Merge Step" diagram https://www.programiz.com/dsa/merge-sort
 */
vector<int> merge(vector<int> leftVec, vector<int> rightVec)
{
    vector<int> resultVec(leftVec.size() + rightVec.size());

    // Append the lowest element b/w leftVec & rightVec into the resultVec in each iteration.
    for (int resIdx = 0, leftIdx = 0, rightIdx = 0; resIdx < resultVec.size(); resIdx++)
    {

        if (leftIdx == leftVec.size() && rightIdx != rightVec.size())
        {
            // Reached the end of leftVec, push back rest of the sorted rightVec into resultVec
            resultVec.at(resIdx) = rightVec.at(rightIdx);
            rightIdx++;
        }
        else if (leftIdx != leftVec.size() && rightIdx == rightVec.size())
        {
            // Reached the end of rightVec, push back rest of the sorted leftVec into resultVec
            resultVec.at(resIdx) = leftVec.at(leftIdx);
            leftIdx++;
        }
        else if (leftVec.at(leftIdx) < rightVec.at(rightIdx))
        {
            // Append the lowest b/w leftVec & rightVec
            resultVec.at(resIdx) = leftVec.at(leftIdx);
            leftIdx++;
        }
        else
        {
            // Append the lowest b/w leftVec & rightVec
            resultVec.at(resIdx) = rightVec.at(rightIdx);
            rightIdx++;
        }
    }

    return resultVec;
}

/**
 * @brief Recursively divides the vec into the smallest units, passes it to the merge(..) & returns a sorted vector.
 */
vector<int> mergeSort(vector<int> vec)
{

    if (vec.size() <= 1)
    {
        // Invalid array sizes.
        return vec;
    }
    else
    {
        int mid = vec.size() / 2;

        vector<int> leftVec(mergeSort(vector<int>(vec.begin(), vec.begin() + mid)));
        vector<int> rightVec(mergeSort(vector<int>(vec.begin() + mid, vec.end())));

        return merge(leftVec, rightVec);
    }
}

int main()
{
    vector<int> vec = {1, 2, 3, 2, 4, 5, 3, 6, 7, 1};
    cout << "Original Vector: " << vectorToString(vec) << endl;
    cout << "Sorted Vector: " << vectorToString(mergeSort(vec)) << endl;
    return 0;
}
