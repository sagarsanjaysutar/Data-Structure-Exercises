/**
 * \brief QuickSort: Divide & Conquer. Select a pivot point. 
 * On left would be values less than pivot & on right values greater than pivot.
*/

#include <iostream>
#include <vector>
#include "Utils.cpp"

using namespace std;

int rearrangeVec(vector<int>& vec, int low, int high){
    
    // Right most element is the pivot.
    int pivotIdx = high;

    int idx = low;

    // Place all the smaller elements to the left & move the greater element to the right of the pivot.
    while(idx < pivotIdx){
        if(vec.at(idx) > vec.at(pivotIdx)){
            int maxVal = vec.at(idx);
            // cout << vectorToString(vec) << endl;

            // Place the maxVal at the end of vector & shift all elements backward by 1.
            for(int i = idx; i < high; i++){
                // cout << maxVal << "\t" << vectorToString(vec) << endl;
                vec.at(i) = vec.at(i + 1);
            }
            vec.at(high) = maxVal;

            // Since maxVal is moved to the end, pivot is shifted by -1
            pivotIdx--;

            if(vec.at(idx) > vec.at(pivotIdx)){
                continue;
            }
        }
        
        idx++;
    }
    
    // cout << "Final \t" << vectorToString(vec) << "\t"<< pivotIdx << endl;
    // cout << pivotIdx << "\t" << low << "\t" << high << endl;
    return pivotIdx;

}


void quickSort(vector<int>& vec, int low, int high){
    if(high < low){
        return;
    }
     
    int pi = rearrangeVec(vec, low, high);
    // recursive call on the left of pivot
    
    quickSort(vec, low, pi - 1);
    quickSort(vec, pi + 1, high);

}

int main(){
    vector<int> vec({8, 1, 2, 3, 2, 4, 5, 3, 6, 7, 1});
    quickSort(vec, 0, vec.size() - 1);

    cout << "xx" << vectorToString(vec) << endl;
    return 0;
}