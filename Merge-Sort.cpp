#include <iostream>
#include <vector>
using namespace std;


void printVec(vector<int> x){
    for(int element :  x){
        cout << element << " ";
    }
    cout << "\n";
}

vector<int> merge(vector<int> leftVec, vector<int> rightVec){
    vector<int> result;
    result.reserve(leftVec.size() + rightVec.size());

    if(leftVec.size() == 1 && rightVec.size() == 1){
        
        if(leftVec.at(0) < rightVec.at(0)){
            result.push_back(leftVec.at(0));
            result.push_back(rightVec.at(0));
        }
        else{
            result.push_back(rightVec.at(0));
            result.push_back(leftVec.at(0));
        }
        cout << "Both size 1: ";
        printVec(result);
        return result;
    }
    
    cout << "Left Vec: ";
    printVec(leftVec);
    cout << "Right Vec: ";
    printVec(rightVec);
    for(int i = 0, j = 0, k = 0; i < result.size(); i++){

        if(leftVec.at(j) < rightVec.at(k)){
            cout << "Left small \n";
            result.push_back(leftVec.at(j));
            j++;
        }
        else{
            cout << "Right small \n";
            result.push_back(rightVec.at(k));
            k++;
        }

        if(j == leftVec.size() - 1 && k != rightVec.size()){
            cout << "Push back rest of the K's element\n";
            result.insert(result.end(), rightVec.begin() + k, rightVec.end());
        }
        else if(j != leftVec.size() - 1 && k == rightVec.size()){
            cout << "Push back rest of the J's element\n";
            result.insert(result.end(), leftVec.begin() + j, leftVec.end());
        }            
    }

    cout << "Both size > 1: ";
    printVec(result);
    return result;
}

vector<int> mergeSort(vector<int> vec){
    cout << "-- " << vec.size() << " | ";
    printVec(vec);
    
    if (vec.size() == 1) {
        return vec;
    }
    else
    {
        int start = vec.at(0);
        int end = vec.size() - 1;
        int mid = vec.size() / 2;

        cout << "xxxxxx\n";
        vector<int> leftVec(mergeSort(vector<int>(vec.begin(), vec.begin() + mid)));
        cout << "=====\n";
        vector<int> rightVec(mergeSort(vector<int>(vec.begin() + mid, vec.end())));
        cout << "yyyyy\n";

        return merge(leftVec, rightVec);
    }
}


int main(){
    
    vector<int> x = {8, 12, 17, 13, 8};
    cout << "pppppppppppppp ";
    printVec(mergeSort(x));
    cout << "\n\n";

    return 0;
}



