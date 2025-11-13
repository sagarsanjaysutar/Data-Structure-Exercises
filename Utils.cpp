/**
 * @brief Utility functions for testing and debugging algorithms.
 */
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <vector>

using namespace std;

/**
 * @brief Returns a string form of an int vector.
 */
string vectorIntToString(vector<int> vec) {
    stringstream vecStr;
    vecStr << "{";
    for (int i = 0; i < vec.size(); ++i) {
        vecStr << vec[i];
        if (i < vec.size() - 1)
            vecStr << ", ";
    }
    vecStr << "}";
    return vecStr.str();
}

/**
 * @brief Returns a string form of a string vector.
 */
string vectorStringToString(vector<string> vec) {
    stringstream vecStr;
    vecStr << "{";
    for (int i = 0; i < vec.size(); ++i) {
        vecStr << vec[i];
        if (i < vec.size() - 1)
            vecStr << ", ";
    }
    vecStr << "}";
    return vecStr.str();
}

/**
 * @brief Returns a string form of a boolean vector.
 */
string vectorBoolToString(vector<bool> vec) {
    stringstream vecStr;
    vecStr << "{";
    for (int i = 0; i < vec.size(); ++i) {
        vecStr << (vec[i] ? "True" : "False");
        if (i < vec.size() - 1)
            vecStr << ", ";
    }
    vecStr << "}";
    return vecStr.str();
}

/**
 * @brief Returns a random integer from the given range.
 * @ref Got this code from Perplexity.
 */
int getRandomNumber(int low, int high) {
    static std::mt19937 gen{std::random_device{}()};
    return std::uniform_int_distribution<>(low, high)(gen);
}

/**
 * @brief Returns a random int vector. 
 * This is to stress test the code on variety of vectors.
 */
vector<int> getRandomVector() {
    map<int, vector<int>> randomVectors;

    randomVectors[0] = {3, 4, 5, 2, 3, 4, 5, 3, 34, 5};
    randomVectors[1] = {1, 6, 3};
    randomVectors[2] = {1, 6, 3, 0};
    randomVectors[3] = {5, 5, 5, 5, 5};
    randomVectors[4] = {1, 3, 1, 3, 1, 3};
    randomVectors[5] = {1, 2, 3, 4, 5, 6};
    randomVectors[6] = {6, 5, 4, 3, 2, 1};
    randomVectors[7] = {42};
    randomVectors[8] = {3, 7};
    randomVectors[9] = {7, 3};
    randomVectors[10] = {9, 1, 2, 3, 4};
    randomVectors[11] = {1, 2, 3, 4, 9};
    randomVectors[12] = {3, 100, 3, 3, 1, 3, 3};
    randomVectors[13] = {5, 1, 2, 10, 15};
    randomVectors[14] = {50, 10, 30, 20, 10, 40, 30, 20, 50, 10};
    randomVectors[15] = {3, 4, 5, 2, 3, 4, 5, 3, 34, 5};
    randomVectors[16] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    randomVectors[17] = {0, 3, 6, 0, 1, 0, 0};
    randomVectors[18] = {3, 100, 3, 3, 1, 3, 3};
    randomVectors[19] = {0, 1, 6, 1, 3, 0, 1, 1};
    randomVectors[20] = {9, 0, 7, 6, 5, 0, 3, 2, 1, 0};
    randomVectors[21] = {51, 132, 349, 204, 426, 388, 462, 105, 324, 0};

    return randomVectors.at(getRandomNumber(0, randomVectors.size() - 1));
}

/**
 * @brief Prints a "vector-of-vector" variable. 
 * Useful while debugging.
 */
void printVectorOfVectors(const vector<vector<int>> &vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "Path " << i << ": [";
        for (size_t j = 0; j < vec[i].size(); ++j) {
            cout << vec[i][j];
            if (j + 1 < vec[i].size())
                cout << ", ";
        }
        cout << "] No. of elements: " << vec[i].size() << "\n";
    }
}
