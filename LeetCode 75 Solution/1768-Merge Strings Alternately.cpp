/**
 * Merge Strings Alternately
 *
 * @ref https://leetcode.com/problems/merge-strings-alternately/description/
 */
#include <iostream>

using namespace std;

int main()
{
    // string word1 = "abc", word2 = "pqr";
    string word1 = "ab", word2 = "pqrs";
    // string word1 = "abcd", word2 = "pq";
    string result;

    if (word1.length() < 1 || word2.length() > 100)
    {
        // Invalid word length.
        cout << "Invalid word length." << endl;
        result = "";
        return -1;
    }
    else if (word1.length() == word2.length())
    {
        // If word length is equal then iterate any of word & append accordingly.
        for (int word1Itr = 0; word1Itr < word1.length(); word1Itr++)
        {
            result.push_back(word1.at(word1Itr));
            result.push_back(word2.at(word1Itr));
        }
    }
    else if (word1.length() > word2.length())
    {
        // If word1 length is greater, then iterate word2 to avoid array-out-of-range error.
        for (int word2Itr = 0; word2Itr < word2.length(); word2Itr++)
        {
            result.push_back(word1.at(word2Itr));
            result.push_back(word2.at(word2Itr));
        }
        // Append the remaining words.
        result.append(string(word1.begin() + word2.length(), word1.end()));
    }
    else if (word1.length() < word2.length())
    {
        // If word2 length is greater, then iterate word1 to avoid array-out-of-range error.
        for (int word1Itr = 0; word1Itr < word1.length(); word1Itr++)
        {
            result.push_back(word1.at(word1Itr));
            result.push_back(word2.at(word1Itr));
        }
        // Append the remaining words.
        result.append(string(word2.begin() + word1.length(), word2.end()));
    }
    cout << "Result:\t" << result << endl;

    return 0;
}
