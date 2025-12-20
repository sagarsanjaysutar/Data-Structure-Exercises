#include <iostream>
#include "../Utils.cpp"
#include <vector>
#include <algorithm>

int strStr1(string haystack, string needle)
{
    int needleSize = needle.size();
    int haystackSize = haystack.size();
    if (needleSize == 0 || haystackSize == 0)
    {
        return -1;
    }

    vector<string> haystackVec;
    string haystackWord(1, haystack.at(0));

    for (int idx = 1; idx < haystackSize; idx++)
    {
        if (idx % needleSize == 0)
        {
            cout << "Cutting at " << idx << endl;
            haystackVec.push_back(haystackWord);
            haystackWord = "";
        }
        haystackWord.push_back(haystack.at(idx));
    }

    if (!haystackWord.empty())
    {
        haystackVec.push_back(haystackWord);
    }

    vector<string>::iterator needlePos = find(haystackVec.begin(), haystackVec.end(), needle);
    if (needlePos == haystackVec.end())
        return -1;
    else
        return (needleSize * (needlePos - haystackVec.begin()));
}

int strStr(string haystack, string needle)
{
    int needleSize = needle.size();
    int haystackSize = haystack.size();

    // Constraint Check
    if (needleSize == 0 || haystackSize == 0)
    {
        return -1;
    }

    // No need to iterate till last word of haystack.
    // Reasoning: e.g. While searching for 'sad'(3 char) in 'happensad'(9
    // char), we only need to iterate till 6th pos. because from 7th pos.
    // there are no 3 chars.
    for (int idx = 0; idx <= haystackSize - needleSize; idx++)
    {

        // Check the occurance of needle using first & last char & if true
        // build the word in haystack to verify.
        if (haystack.at(idx) == needle.at(0) &&
            haystack.at(idx + needleSize - 1) ==
                needle.at(needleSize - 1))
        {
            string needleWord;
            for (int n = 0; n < needleSize; n++)
            {
                needleWord.push_back(haystack.at(idx + n));
            }

            // Word found, return idx.
            if (needleWord == needle)
            {
                return idx;
            }
        }
    }

    return -1;
}
int main()
{
    // string haystack = "sadbutsad", needle = "but";
    string haystack = "mississippi", needle = "ippi";

    cout << strStr(haystack, needle) << endl;

    return 0;
}