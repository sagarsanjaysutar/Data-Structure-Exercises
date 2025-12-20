/**
 * @ref https://leetcode.com/problems/longest-common-prefix/description/
 */
#include <iostream>
#include <vector>
#include "../Utils.cpp"

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string longestPrefix;
    int vecSize = strs.size();

    // #00. Constraint checks
    if (vecSize > 200 || vecSize < 1)
    {
        return longestPrefix;
    }
    if (vecSize == 1)
    {
        return strs.at(0);
    }

    // #01. The solution involves iterating each characters of every string in the given vector.
    //      We can only iterate till the last character of the smallest word.
    //      e.g {"flower","flow","flight"}, in this vector, we can only check first 4 chars. because smallest word; flow is of 4 chars.
    //      if iterate beyond 4, there would be out-of-bound error while iterating "flow".
    //
    //      Initialise with the size of first element. Cannot initialise with 0 because there are no valid words at size 0.
    int smallestWordSize = strs.at(0).size();

    for (int idx = 0; idx < vecSize; idx++)
    {
        if (strs.at(idx).size() < smallestWordSize)
        {
            smallestWordSize = strs.at(idx).size();
        }
    }

    // If the size of smallest word is 0, it means it is "". No common prefix can be found.
    if (smallestWordSize == 0)
    {
        return longestPrefix;
    }

    // #02. Main logic. The idea is to iterate each element in the vector<string> & check each of the char.
    // Initialise with true to keep the loop running.
    bool isCommonPrefixPresent = true;

    // The current idx of vector<string>
    int stringIdx = 0;

    // The char. idx across all elements of vector<string>
    int charIdx = 0;

    while (isCommonPrefixPresent)
    {
        if (charIdx == smallestWordSize)
        {
            // Safety Check. If char. idx points to the last idx of the smallest word, then we have to break the loop. Refer #01.
            break;
        }
        else if (stringIdx == vecSize - 1)
        {
            // If this condition is reached, it means all the char. pointed at by charIdx across all elements of vectors have been checked.
            // Thus that char. can be added to the result string
            longestPrefix.push_back(strs.at(stringIdx).at(charIdx));
            stringIdx = 0;
            charIdx++;
        }
        else if (strs.at(stringIdx).at(charIdx) ==
                 strs.at(stringIdx + 1).at(charIdx))
        {
            // Verifies common prefix. If found, move onto next element of vector<string>
            stringIdx++;
        }
        else
        {
            // If the above condition fails, it means no common prefix is present.
            isCommonPrefixPresent = false;
        }
    }

    return longestPrefix;
}

int main()
{
    vector<string> vec = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(vec) << endl;
    return 0;
}