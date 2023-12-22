/**
 * @brief Merge Sort
 * @note Time complexity: n log(n): mergeSort(...) works in "log(n)" as it divides the input &
 * merge(...) works in "n" as it has single loop.
*/

#include <iostream>
#include <vector>
#include "Utils.cpp"

using namespace std;

/**
 * @brief Sorts & merges two vector. 
 * @ref Refer the "Merge Step" diagram https://www.programiz.com/dsa/merge-sort 
*/
vector<int> merge(vector<int> leftVec, vector<int> rightVec){
    vector<int> result(leftVec.size() + rightVec.size());
    
    // Append the lowest element b/w leftVec & rightVec into result in each iteration.  
    for(int resIdx = 0, leftIdx = 0, rightIdx = 0; resIdx < result.size(); resIdx++){

        if(leftIdx == leftVec.size() && rightIdx != rightVec.size()){
            // Reached the end of leftVec, push back rest of the rightVec.
            result.at(resIdx) = rightVec.at(rightIdx);
            rightIdx++;
        }
        else if(leftIdx != leftVec.size() && rightIdx == rightVec.size()){
            // Reached the end of rightVec, push back rest of the leftVec.
            result.at(resIdx) = leftVec.at(leftIdx);
            leftIdx++;
        } 
        else if(leftVec.at(leftIdx) < rightVec.at(rightIdx)){
            // Append the lowest b/w leftVec & rightVec
            result.at(resIdx) = leftVec.at(leftIdx);
            leftIdx++;
        }
        else{
            // Append the lowest b/w leftVec & rightVec
            result.at(resIdx) = rightVec.at(rightIdx);
            rightIdx++;
        }
    }

    return result;
}

/**
 * @brief Recursively divides the vec into the smallest units, passes it to the merge(..) & returns a sorted vector.
*/
vector<int> mergeSort(vector<int> vec){
    
    if (vec.size() <= 1) {
        // Invalid array sizes.
        return vec;
    }
    else
    {
        int start = vec.at(0);
        int end = vec.size() - 1;
        int mid = vec.size() / 2;

        vector<int> leftVec(mergeSort(vector<int>(vec.begin(), vec.begin() + mid)));
        vector<int> rightVec(mergeSort(vector<int>(vec.begin() + mid, vec.end())));

        return merge(leftVec, rightVec);
    }
}


int main(){
    vector<int> x = {1, 2, 3, 2, 4, 5, 3, 6, 7, 1};

    cout << "Original Vector: " << vectorToString(x);
    cout << "Sorted Vector: " << vectorToString(mergeSort(x));

    return 0;
}



