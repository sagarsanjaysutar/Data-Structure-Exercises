/**
 * \brief Maximum Contiguous Subsequence Sum
 * Given (possibly negative) integers A1, A2,.., An,
 * Find and identify the sequence whose sum is the maximum.
 * The maximum contiguous subsequence sum is zero if all the integers are negative.
 *
 * e.g  In (-2, 11, -4, 13, -5, 2), {11, -4, 13} sequence results in the highest sum.
 *
 * @ref Pg. 199: Data Structures And Problem Solving Using C++ 2nd ed - Mark Weiss.
 */
#include <iostream>
#include <vector>

using namespace std;

float useLinearSolution(vector<float> numVec, float &startNum, float &endNum)
{
    float maxSum = 0, iterSum = 0;
    for (int i = 0, j = 0; j < numVec.size(); j++)
    {
        iterSum += numVec.at(j);
        // cout << i << "\t" << j << "\t" << iterSum << endl;

        // Check if max sum is found.
        if (iterSum > maxSum)
        {
            maxSum = iterSum;
            startNum = numVec.at(i);
            endNum = numVec.at(j);
        }

        // If the seq. sum from vec[i] to vec[j], is negative then skip the whole sequence.
        // The sequence is skipped by setting i to j+1, & then j starts from 0.
        // Refer Theorem 6.2, Pg. 205
        if (iterSum < 0)
        {
            i = j + 1;
            iterSum = 0;
        }
    }

    return maxSum;
}
float useQuadraticSolution(vector<float> numVec, float &startNum, float &endNum)
{
    float maxSum = 0;

    for (int itr = 0; itr < numVec.size(); itr++)
    {
        float iterSum = 0;
        for (int jItr = itr; jItr < numVec.size(); jItr++)
        {
            // cout << itr << "\t" << jItr << edl;

            // Keeps adding numbers b/w itr & jItr.
            iterSum += numVec.at(jItr);

            // Check if max sum is found.
            if (iterSum > maxSum)
            {
                maxSum = iterSum;
                startNum = numVec.at(itr);
                endNum = numVec.at(jItr);
            }
        }
    }

    return maxSum;
}

int main()
{
    vector<float> numVec = {1, -3, 4, -2, -1, 6};
    float startNum, endNum, maxSum;
    maxSum = useLinearSolution(numVec, startNum, endNum);
    cout << "Sequence starting from " << startNum << " to " << endNum << " results in maximum sum = " << maxSum << endl;

    return 0;
}