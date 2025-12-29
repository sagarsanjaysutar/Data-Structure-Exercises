
/**
 * @brief This was just a random thought because I had already written program to find second largest number.
 */
#include "../Utils.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {51, 132, 349, 204, 426, 388, 462, 105, 324, 110};

  // Find the smallest number first.
  int firstSmallestNumber = INT32_MAX;
  for (int i = 0; i < v.size(); i++) {
    if (v.at(i) <= firstSmallestNumber) {
      firstSmallestNumber = v.at(i);
    }
  }

  // Using the smallest number as upper-limit, find the second smallest number.
  int secondSmallestNumber = INT32_MAX;
  for (int i = 0; i < v.size(); i++) {
    if (v.at(i) <= secondSmallestNumber && v.at(i) > firstSmallestNumber) {
      secondSmallestNumber = v.at(i);
    }
  }

  cout << "Original Vector: " << vectorIntToString(v) << endl;
  cout << "FirstSmallestNumber: " << firstSmallestNumber << endl;
  cout << "SecondSmallestNumber: " << secondSmallestNumber << endl;

  return 0;
}