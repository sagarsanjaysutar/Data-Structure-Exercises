#include <iostream>
#include <sstream>
#include <vector>


/**
 * @brief Helper function to print vector.
*/
std::string vectorToString(std::vector<int> vec) {
    std::stringstream vecStr;
    vecStr << "{";
    for (int i = 0; i < vec.size(); ++i) {
        vecStr << vec[i];
        if (i < vec.size() - 1)
            vecStr << ", ";
    }
    vecStr << "}\n";
    return vecStr.str();
}