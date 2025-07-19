/**
 * @brief Quick Sort with middle pivot
 *
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

vector<int> rearrangeVec(vector<int> vec)
{

    int pivotIdx = vec.size() / 2;

    int leftPtr = 0;
    int rightPtr = vec.size() - 1;

    int smallIdx, bigIdx;
    bool leftSwap = false, rightSwap = false;

    int idx = 0;

    while (true)
    {
        idx++;
        cout << pivotIdx << "\t" << leftPtr << "\t" << rightPtr << "\t" << vectorToString(vec) << endl;
        if (leftPtr >= rightPtr)
        {
            cout << "Break\n";
            break;
        }

        if (vec.at(leftPtr) >= vec.at(pivotIdx))
        {
            bigIdx = leftPtr;
            cout << "Greater element found on left: " << vec.at(leftPtr) << endl;
            leftSwap = true;
        }
        else
        {
            leftPtr++;
        }

        if (vec.at(rightPtr) <= vec.at(pivotIdx))
        {
            smallIdx = rightPtr;
            cout << "Lesser element found on right: " << vec.at(rightPtr) << endl;
            rightSwap = true;
        }
        else
        {
            rightPtr--;
        }

        if (leftSwap && rightSwap)
        {
            cout << "Swapping " << vec.at(bigIdx) << " & " << vec.at(smallIdx) << endl;
            swap(vec.at(smallIdx), vec.at(bigIdx));
            leftSwap = false;
            rightSwap = false;
        }
    }

    return vec;
}

vector<int> quickSort(vector<int> vec)
{
    if (vec.size() <= 1)
    {
        return vec;
    }
    else
    {
        cout << "\n\nSorting " << vectorToString(vec) << endl;
        int pivotIdx = vec.size() / 2;
        vector<int> rearrangedVec = rearrangeVec(vec);

        vector<int> leftVec(quickSort(vector<int>(rearrangedVec.begin(), rearrangedVec.begin() + pivotIdx)));
        vector<int> rightVec(quickSort(vector<int>(rearrangedVec.begin() + pivotIdx, rearrangedVec.end())));

        // Merge the two sorted vector
        leftVec.insert(leftVec.end(), rightVec.begin(), rightVec.end());

        return leftVec;
    }
}

int main()
{
    vector<int> vec({3, 4, 5, 2, 3, 4, 5, 3, 34, 5});
    // vector<int> vec({51, 132, 349, 204, 426, 388, 462, 105, 324, 0});
    cout << "Original Vector: " << vectorToString(vec) << endl;
    vector<int> sortedVec(quickSort(vec));
    cout << "Sorted Vector: " << vectorToString(sortedVec) << endl;
    return 0;
}