/**
 * Reverse Vowels of a String
 *
 * @ref https://leetcode.com/problems/reverse-vowels-of-a-string
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include "../Utils.cpp"

using namespace std;

string reverseVowels(string s)
{
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    // Find out the vowel position & the corresponding char in the string.
    vector<int> vowelPositions;
    vector<int> vowelChar;
    for (int idx = 0; idx < s.size(); idx++)
    {
        if (find(vowels.begin(), vowels.end(), s.at(idx)) != vowels.end())
        {
            vowelPositions.push_back(idx);
            vowelChar.push_back(s.at(idx));
        }
    }

    // Reverse the vowel positions vector.
    vector<int> reverseVowelPositions;
    for (int idx = vowelPositions.size() - 1; idx >= 0; idx--)
    {
        reverseVowelPositions.push_back(vowelPositions.at(idx));
    }

    // Replace the vowels in original string with reversed-vowels.
    for (int idx = 0; idx < reverseVowelPositions.size(); idx++)
    {
        s.at(reverseVowelPositions.at(idx)) = vowelChar.at(idx);
    }

    return s;
}

string reverseVowelsPtr(string s)
{
    string vowels = "aeiouAEIOU";

    // Left & right pointers.
    int left = 0, right = s.size() - 1;

    // Indicates when to swap the left & right characters.
    bool leftSwap, rightSwap;

    while (true)
    {
        if (left >= right)
        {
            // Break the loop when left surpasses right.
            break;
        }

        if (vowels.find(s.at(left)) != string::npos)
        {
            // Vowel found on left pointer.
            leftSwap = true;
        }
        else
        {
            // Vowel not found on left, increment the pointer.
            left++;
        }

        if (vowels.find(s.at(right)) != string::npos)
        {
            // Vowel found on right pointer.
            rightSwap = true;
        }
        else
        {
            // Vowel not found on right, decrement the pointer.
            right--;
        }

        if (leftSwap && rightSwap)
        {
            // Swapping both left & right character.
            swap(s.at(left), s.at(right));

            // Move the pointer after swapping.
            left++;
            right--;

            // Reset the flags.
            leftSwap = false;
            rightSwap = false;
        }
    }

    return s;
}

int main()
{
    string s = "IceCreAm";

    cout << "Original string: " << s << endl;
    cout << "Reversed vowel string: " << reverseVowels(s) << endl;
    cout << "Reversed vowel string (using 2 pointer): " << reverseVowelsPtr(s) << endl;

    return 0;
}