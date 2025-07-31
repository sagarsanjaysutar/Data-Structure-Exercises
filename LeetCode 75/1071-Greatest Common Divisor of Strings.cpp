/**
 * Greatest Common Divisor of Strings
 *
 * @ref https://leetcode.com/problems/greatest-common-divisor-of-strings/description
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include "../Utils.cpp"

using namespace std;

// Removes denominator from the numerator & checks if result is "".
// It true, it means denominator is the divisor.
bool isGCD(string numerator, string denominator)
{
    size_t pos = 0;

    while ((pos = numerator.find(denominator)) != string::npos)
    {
        numerator.erase(pos, denominator.length());
    }
    return numerator == "";
}

int main()
{
    // string str1 = "ABCABC", str2 = "ABC";
    string str2 = "ABABAB", str1 = "ABAB";
    // string str2 = "ABCABC", str1 = "BCABCA";
    // string str1 = "LEET", str2 = "CODE";

    // Represents the divisor we'd be using to determine GCD.
    string divisor;

    // Represents the final result. A divisor that is common b/w both strings & is the largest.
    string gcd;

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
                if (isGCD(str1, divisor) && isGCD(str2, divisor))
                {
                    gcd = divisor;
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
                if (isGCD(str1, divisor) && isGCD(str2, divisor))
                {
                    gcd = divisor;
                }
            }
        }
    }

    cout << "Result: " << gcd << endl;

    return 0;
}
