/**
 * @brief An example of Linear algorithm O(N) as we have 1 loop that iterates through all elements to find the minimum number.
 * The running time of this program will increase with size of input. *
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numVec = {45, 43, 84, 33, 11, 9, 84, 3};
    int minNum;
    for (int num = 0; num < numVec.size(); num++)
    {

        // Check if last element is the smallest number.
        if (num == numVec.size() - 1 && numVec.at(numVec.size() - 1) < minNum)
        {
            minNum = numVec.at(numVec.size() - 1);
            break;
        }

        // Check if rest of the elements are smaller as compared to the following elements.
        if (numVec.at(num) < numVec.at(num + 1))
        {
            minNum = numVec.at(num);
        }
    }

    cout << "Minimum Number: \t" << minNum << endl;
    return 0;
}
