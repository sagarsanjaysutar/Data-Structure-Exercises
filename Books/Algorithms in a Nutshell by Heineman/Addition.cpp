/**
 * @brief Manual Addition & Substraction of digits.
 * The purpose of this exercise is to learn the cost of arithmetic operations.
 * @note Time complexity: O(n) Linear
 *
 * @ref Pg. 33: Algorithms in a Nutshell by Heineman.
 */
#include "../../Utils.cpp"
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/**
 * @brief Resizes the array to new length & prepends padValue.
 */
vector<int> padVectorFront(vector<int> v, int newLength, int padValue) {
    // Note: Deque is used for efficient prepending.
    deque<int> d(v.begin(), v.end());
    for (int idx = 0; idx < newLength; idx++) {
        d.push_front(padValue);
    }
    return vector<int>(d.begin(), d.end());
}

/**
 * @brief Adds two number with equal no. of digits.
 * */
int add(vector<int> &x, vector<int> &y) {

    // Equalize vector lengths for easier calculations.
    int xSize = x.size();
    int ySize = y.size();
    if (xSize > ySize) {
        y = padVectorFront(y, xSize - ySize, 0);
    }
    if (ySize > xSize) {
        x = padVectorFront(x, ySize - xSize, 0);
    }

    // Given that x & y have same no. of digits, the max size of sum can only be x.size + 1.
    // e.g. 9999 + 9999 = 19998, note that the size of result is x.size + 1.
    vector<int> sum(x.size() + 1);

    // A pointer pointing to the last element of x as we add digits from right to left.
    int pointer = x.size() - 1;
    int carry = 0;

    while (pointer >= 0) {

        int total = x.at(pointer) + y.at(pointer) + carry; // Add digit of x & y + carry.
        if (total > 9) {

            // If the sum of two digits is greater than 9:
            // a. Carry over 1 to the next digit addition.
            // b. Append the remainder to the result.

            //! @brief Calculate the remainder.

            // Method 1: remainder = (sum% 0)
            //! @note Inefficient as % is expensive operation
            // e.g. if total is 18, the remainder "8" gets added to the result & 1 gets carried.
            // int remainder = total % 10;

            // Method 2: Clever alternative
            //! @note Comparatively Efficient
            // e.g. if the total is 18, the remainder "8" is calculated by substracting 10.
            // This is a clever mathematical observation which works on addition of 2 single digit number.
            // A single digit number whose max value is 9.
            int remainder = total - 10;

            // Note that the + 1 is so that we can have an extra element in the beginning of the sum vector
            sum.at(pointer + 1) = remainder;
            carry = 1;
        } else {
            sum.at(pointer + 1) = total;
            carry = 0;
        }

        sum.at(0) = carry;
        pointer--;
    }

    stringstream sumStream("", ios_base::app | ios_base::out);
    for (int digit : sum) {
        sumStream << std::to_string(digit);
    }

    return stoi(sumStream.str());
}

/**
 * @brief Subtracts two number with equal no. of digits
 * @note Limitations: x > y.
 * The reverse isn't supported because in order to determine if y > x,
 * we'd have to build the integer out of the vectors & then do the comparison.
 * This defeats the purpose of this exercise.
 */
int sub(vector<int> &x, vector<int> &y) {

    // Equalize vector lengths for easier calculations.
    int xSize = x.size();
    int ySize = y.size();
    if (xSize > ySize) {
        y = padVectorFront(y, xSize - ySize, 0);
    }
    if (ySize > xSize) {
        x = padVectorFront(x, ySize - xSize, 0);
    }

    // Given that x & y have same no. of digits, the max size of subtracted no. can only be <= x.size.
    // e.g. 9999 - 1111 = 8888, here the size of result can never be more than x.
    vector<int> res(x.size());

    // A pointer pointing to the last element of x as we subtract digits from right to left.
    int pointer = x.size() - 1;

    while (pointer >= 0) {
        if (x.at(pointer) >= y.at(pointer)) {
            res.at(pointer) = x.at(pointer) - y.at(pointer);
        } else {
            // +10 as we've borrowed 1 from the preceding element.
            res.at(pointer) = (x.at(pointer) + 10) - y.at(pointer);

            // Subtracting the borrowed 1 from the preceding element.
            // Note that this only works as we've assumed x > y,
            // if y > x, then borrowing for 0th number would be mathematically illegal.
            x.at(pointer - 1) = x.at(pointer - 1) - 1;
        }
        pointer--;
    }

    stringstream sumStream("", ios_base::app | ios_base::out);
    for (int digit : res) {
        sumStream << std::to_string(digit);
    }

    return stoi(sumStream.str());
}

int main() {
    vector<int> x = {9, 8, 6, 1, 9};
    vector<int> y = {1, 1, 1, 1};
    cout << "Sum of adding " << vectorIntToString(x) << " and " << vectorIntToString(y) << ": " << add(x, y) << endl;
    cout << "Substracting " << vectorIntToString(x) << " from " << vectorIntToString(y) << ": " << sub(x, y) << endl;
    return 0;
}