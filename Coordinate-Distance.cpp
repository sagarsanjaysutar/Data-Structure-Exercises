/**
 * @brief Closest points in the plane: Given n points in a plane (that is, an x-y coordinate system),
 *  find the pair of points that are closest together. Pg. 198. DS & PS using C++
 * 
 * This is a quadratic solution O(N)^2 as there are 2 loops. * 
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

float getDistance(vector<int> ptA, vector<int>ptB){
    if (ptA.size() == 2 && ptB.size() == 2) {
        // Given ptA(x1, y1) & ptB(x2, y2), Distance = Square root of (x2 - x1)^2 + (y2 - y1)^2
        return sqrt( pow((ptB.at(0) - ptA.at(0)), 2) + pow((ptB.at(1) - ptA.at(1)), 2));
    }
    else {
        cout << "Invalid vector size." << endl; 
        return 0;
    }
}

string printVec(vector<int> vec){
    if (vec.size() == 2) {
        return "(" + std::to_string(vec[0]) + ", " + std::to_string(vec[1]) + ")";
    } else {
        return "Invalid vector size.";
    }
}

int main()
{
    // Vector of coordinates
    vector<vector<int>> coordinateVec = { 
        {12, 68}, {45, 89}, {99, 23}, {78, 64},
        {34, 57}, {60, 5}, {2, 9}, {87, 77},
        {54, 30}, {72, 94}
    };

    float minDistance = 0;
    vector<vector<int>> resCoordinate(2);

    // Combination of all the coordinates.
    // One coordinate is selected by the Outer loop & combined with rest of the coordinate using inner loop.
    for(int outerItr = 0; outerItr < coordinateVec.size(); outerItr++){        

        // innerItr = outerItr + 1 as we do not want the combination of same coordinate e.g. {(5,5), (5,5)}
        for(int innerItr = outerItr + 1; innerItr < coordinateVec.size(); innerItr++){

            vector<int> ptA(coordinateVec.at(outerItr)), ptB(coordinateVec.at(innerItr));
            float distance = getDistance(ptA, ptB);
            // cout << printVec(ptA) << " " << printVec(ptB) << "\tDistance b/w points: " << distance << endl;

            // Initialise the minDistance variable by assigning the first calculated distance.
            if(outerItr == 0 && innerItr == 1){           
                minDistance = distance;                
            }
            
            // Check if smaller distance is found.
            if(distance < minDistance){
                minDistance = distance;
                resCoordinate = {ptA, ptB};
            }
        }
    }

    cout << printVec(resCoordinate.at(0)) << ", " << printVec(resCoordinate.at(1)) << " are closest with minimum distance: " << minDistance << endl;

    return 0;
}
