#include <iostream>
#include <vector>
using namespace std;


vector<int> merge(vector<int> leftVec, vector<int> rightVec){
    vector<int> result;
    result.reserve(leftVec.size() + rightVec.size());
    result.insert(result.end(), leftVec.begin(), leftVec.end());
    result.insert(result.end(), rightVec.begin(), rightVec.end());
    return result;
}

vector<int> mergeSort(vector<int> vec){

    if (vec.size() == 1) {
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
    
    vector<int> x = {8, 12, 17, 13, 8};
    for(int element :  mergeSort(x)){
        cout << element << " ";
    }


    return 0;
}