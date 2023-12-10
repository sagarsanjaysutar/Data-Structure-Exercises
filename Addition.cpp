#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

/**
 * @brief Adds two number with equal no. of digits.
 * @note Time complexity: Linear
*/
int add(vector<int> x, vector<int> y){

    // x & y should have same no. of digits.
    if(x.size() != y.size()){
        cout << "This function only adds numbers having same no. of digits." << endl;
        return 0;
    }

    // Given that x & y have same no. of digits, the max size of sum can only be x.size + 1.
    // e.g. 9999 + 9999 = 19998, note that the size of result is x.size + 1.
    vector<int> sum(x.size()+1);
    
    // A pointer pointing to the last element of x as we add digits from right to left.
    int pointer = x.size() - 1;
    int carry = 0;

    while(pointer >=0){

        int total = x.at(pointer) + y.at(pointer) + carry;  // Add digit of x & y + carry.
        if(total > 9){            
            //! @note Inefficient as % is expensive operation
            // Gives us the remainder e.g. if total is 18 then we add "8" to the sum vector & 1 gets carried.            
            // int remainder = total % 10;
            
            //! @note Comparatively Efficient
            // This also gives the remainder e.g. if the total is 18, then we get "8".
            // This is only because max digit is 9, therefore the max total of 2 digit will be 18.
            int remainder = total - 10;

            // Note that the + 1 is so that we can have an extra element in the beginning of the sum vector
            sum.at(pointer + 1) = remainder;
            carry = 1;
        }
        else{
            sum.at(pointer + 1) = total;
            carry = 0;
        }

        sum.at(0) = carry;
        pointer--;
    }

    stringstream sumStream("", ios_base::app | ios_base::out);
    for(int digit : sum){
        sumStream << std::to_string(digit);
    }

    return stoi(sumStream.str());
}

/**
 * @brief Subtracts two number with equal no. of digits
 * @note Limitations: x > y.  
 * The reverse isn't supported because in order to determine if y > x, 
 * we'd have to build the integer out of the vectors & then do the comparison.
 * This defeats the purpose of this exercise. 
*/
int sub(vector<int> x, vector<int> y){

    // x & y should have same no. of digits.
    if(x.size() != y.size()){
        cout << "This function only subtracts numbers having same no. of digits." << endl;
        return 0;
    }

    // Given that x & y have same no. of digits, the max size of subtracted no. can only be <= x.size.
    // e.g. 9999 - 1111 = 8888, here the size of result can never be more than x. 
    vector<int> res(x.size());
    
    // A pointer pointing to the last element of x as we subtract digits from right to left.
    int pointer = x.size() - 1;

    while(pointer >=0){
        if(x.at(pointer) >= y.at(pointer)){
            res.at(pointer) = x.at(pointer) - y.at(pointer);
        }
        else{
            // +10 as we've borrowed 1 from the preceding element.
            res.at(pointer) = (x.at(pointer) + 10) - y.at(pointer);

            // Subtracting the borrowed 1 from the preceding element.
            // Note that this only works as we've assumed x > y, 
            // if y > x, then borrowing for 0th number would be mathematically illegal.
            x.at(pointer - 1) = x.at(pointer - 1) - 1;
        }
        pointer--;
    }

    stringstream sumStream("", ios_base::app | ios_base::out);
    for(int digit : res){
        sumStream << std::to_string(digit);
    }

    return stoi(sumStream.str());
}

int main(){
    vector<int> x = {9, 8, 6, 1, 0};
    vector<int> y = {1, 1, 1, 1, 1};
    cout << add(x, y) << endl;
    cout << sub(x, y) << endl;
    return 0;
}