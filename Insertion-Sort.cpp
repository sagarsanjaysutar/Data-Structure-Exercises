/**
 * @brief Insertion Sort
 * Iteratively builds sorted portion of the array by comparing a given element 
 * & inserting it into right position within the sorted array.
 * 
 * @note Time Complexity: O(n^2)
*/
#include <iostream>
#include <vector>
#include "Utils.cpp"

using namespace std;

int main(){

    vector<int> intVec = {1, 2, 3, 2, 4, 5, 3, 6, 7, 1};

    cout << "Original Array: " << vectorToString(intVec);

    for(int i = 1; i < intVec.size(); i++){

        // In each iteration, i & j generates a "sorted" portion of the array.
        int j = i - 1;

        // value being compared.
        int value = intVec.at(i);

        // value is smaller than preceding element, push rest of the element ahead.
        // This is an expensive operation as "values" are being pushed to new memory addresses.
        // A "pointer" based array would've been more efficient.
        while(j >= 0 && value < intVec.at(j)){            
            intVec.at(j + 1) = intVec.at(j);
            j--;
        }

        // value being "inserted" after all elements are pushed ahead.
        intVec.at(j + 1) = value;
    }

    cout << "Sorted Array: " << vectorToString(intVec);
}
