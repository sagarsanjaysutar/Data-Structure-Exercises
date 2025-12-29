/**
 * @brief Find the second largest number in vector
 *
 * This question was asked to me on 5th December 2025 in an interview by persistent.com.
 * I failed to solve it in the interview. I was only able to find the largest number & not the 2nd largest.
 * But I solved it on my own on 20th December once I had LeetCode practice.
 *
 */
#include "../Utils.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {51, 132, 349, 204, 426, 388, 462, 105, 324, 0};

  // Find the largest number first.
  int firstLargestNumber = 0;
  for (int idx = 0; idx < v.size(); idx++) {
    if (v.at(idx) > firstLargestNumber) {
      firstLargestNumber = v.at(idx);
    }
  }

  // Using the largest number as upper-limit, find the second largest number.
  int secondLargestNumber = 0;
  for (int idx = 0; idx < v.size(); idx++) {
    if (v.at(idx) > secondLargestNumber && v.at(idx) < firstLargestNumber) {
      secondLargestNumber = v.at(idx);
    }
  }
  cout << "Original Vector: " << vectorIntToString(v) << endl;
  cout << "FirstLargestNumber: " << firstLargestNumber << endl;
  cout << "SecondLargestNumber: " << secondLargestNumber << endl;

  return 0;
}