/**
 * Greatest Common Divisor of Strings
 * @ref https://leetcode.com/problems/greatest-common-divisor-of-strings/description
 *
 * ## Describe the problem in your own words.
 * @date 15th December 2025
 * The problem states to return a string that is common between two words such that concatinating this common string amongst itself should
 * result in those two words. e.g. ABABAB & ABAB. Amongst these two words, AB is a string such that, after concatinating with itself, it
 * results in ABABAB & ABAB. Note: In this example, ABAB (2nd word) is not common string, because ABAB+ABAB != 1st word (ABABAB).
 *
 * ## What was the approach that solved the problem?
 * @date 15th December 2025
 * The solution involves iterating the smallest word amongst the two. With each iteration, we build a 'divisor' variable consisting of
 * common char. amongst the two word. This 'divisor' variable is checked against the two words to determine if it's common divisor.
 * With each iteration, we end up building largest common-divisor. Thus in the end we find GCD.
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include "../Utils.cpp"

using namespace std;

// Removes denominator from the numerator & checks if result is "".
// If true, it means denominator is the divisor.
bool isDivisor(string numerator, string denominator)
{
    size_t pos = 0;

    // Each iteration finds an instance of dem. in num.
    // Keep iterating until you remove all instances of dem. from num.
    while ((pos = numerator.find(denominator)) != string::npos)
    {
        numerator.erase(pos, denominator.length());
    }
    return numerator == "";
}

int main()
{
    // string str1 = "ABCABC", str2 = "ABC";
    string str1 = "ABABAB", str2 = "ABAB";
    // string str2 = "ABCABC", str1 = "BCABCA";
    // string str1 = "LEET", str2 = "CODE";

    // Represents the divisor/denominator we'd be using to determine GCD.
    string divisor;

    // Represents the final result. A divisor/denominator that is common b/w both strings & is the largest.
    string commonDivisor;

    if (str1.length() < 1 || str2.length() > 1000)
    {
        // Invalid word length.
        return -1;
    }

    // Iterate the smaller string to avoid out-range-error.
    if (str2.length() >= str1.length())
    {
        for (int str1Iter = 0; str1Iter < str1.length(); str1Iter++)
        {
            if (str1.at(str1Iter) == str2.at(str1Iter))
            {
                // Generate the divisor.
                divisor.push_back(str1.at(str1Iter));

                // Check if the divisor is common amongst both the strings.
                if (isDivisor(str1, divisor) && isDivisor(str2, divisor))
                {
                    commonDivisor = divisor;
                }
            }
        }
    }

    // Iterate the smaller string to avoid out-range-error.
    if (str1.length() > str2.length())
    {
        for (int str2Iter = 0; str2Iter < str2.length(); str2Iter++)
        {
            if (str1.at(str2Iter) == str2.at(str2Iter))
            {
                // Generate the divisor.
                divisor.push_back(str1.at(str2Iter));

                // Check if the divisor is common amongst both the strings.
                if (isDivisor(str1, divisor) && isDivisor(str2, divisor))
                {
                    commonDivisor = divisor;
                }
            }
        }
    }

    cout << "Result: " << commonDivisor << endl;

    return 0;
}
