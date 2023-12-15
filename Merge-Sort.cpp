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
    

    if(leftVec.size() == 1 && rightVec.size() == 1){
        cout << "Both size 1\n";
        if(leftVec.at(0) < rightVec.at(0)){
            result.push_back(leftVec.at(0));
            result.push_back(rightVec.at(0));
        }
        else{
            result.push_back(rightVec.at(0));
            result.push_back(leftVec.at(0));
        }
        return result;
    }

    int idx = 0;
    while(leftVec.size() > 1){
        cout << "Sorting left\n";
        if(leftVec.at(idx) < leftVec.at(idx+1))
            result.push_back(leftVec.at(idx));
        else
            result.push_back(leftVec.at(idx));

        idx++;
    }

    int idx = 0;
    while(rightVec.size() > 1){
        cout << "Sorting Right\n";
        if(rightVec.at(idx) < rightVec.at(idx+1))
            result.push_back(rightVec.at(idx));
        else
            result.push_back(rightVec.at(idx));
                    
        idx++;
    }
    
    cout << "Left Vec: ";
    printVec(leftVec);
    cout << "Right Vec: ";
    printVec(rightVec);
    
    result.reserve(leftVec.size() + rightVec.size());
    result.insert(result.end(), leftVec.begin(), leftVec.end());
    result.insert(result.end(), rightVec.begin(), rightVec.end());
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


/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> x){
    for(int element :  x){
        cout << element << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> rightVec = {8, 12, 17, 13, 8};
    vector<int> result;
    
    
    int low = 0;
    for(int i = 0, j = 0; j < rightVec.size()-1; j++){
        
        // if(rightVec.at(j) < rightVec.at(j+1))
        //   result.push_back(rightVec.at(j));
        // else
        //   result.push_back(rightVec.at(j+1));
        cout << i << " " << j << endl;
        
        if(j == rightVec.size() - 1){
            i++;
        }
        
    }
    
    printVec(result);
    return 0;
}
