#include <iostream>
using namespace std;

/**
 * @brief Returns the number of turns it took to guess the target number within the given range using divide & conquer method.
 * @note Time complexity = log n.
 * @ref Niche program found on Pg. 32. Algo in Nutshell
*/
int turns(int targetNum, int startRange, int endRange){
    int turns = 0;

    // Continue until two items are in the range.
    while(endRange - startRange >= 2){
        turns++;
        int mid = (endRange + startRange) / 2;

        if(targetNum == mid){
            cout << "Target found on mid " << mid << " turns " << turns << endl;
            return turns;
        }
        else if(targetNum < mid){
            cout << "Target in the low range." << endl; 
            cout << "- target " << targetNum << " mid " << mid << " turns " << turns << endl;
            cout << "- start range " << startRange << " end range " << endRange << endl;
            endRange = mid - 1;
            cout << "- new start range " << startRange << " end range " << endRange << endl;
        }
        else{
            cout << "Target in the high range.\n";
            cout << "+ target " << targetNum << " mid " << mid << " turns " << turns << endl;
            cout << "+ start range " << startRange << " end range " << endRange << endl;
            startRange = mid + 1;
            cout << "+ new start range " << startRange << " end range " << endRange << endl;
        }       
        cout << "\n";
    }

    // If program reaches this point, it means 2 things
    // 1. The while loop has been terminated as only two items, (low & high) are remaining in the range.
    // 2. The target wasn't found on the mid (line 16).
    // Thus, one of the low or high is our target numbers. This is an "intelligent" guess outside the while loop.
    // We count this guess as another "turn" thus we increment the turn by 1.
    return ++turns;
}


int main(){
    int targetNum = 1;
    int startRange = 0;
    int endRange = 10;
    
    int turn = turns(targetNum, startRange, endRange);
    cout << "It took " << turn << " turns to guess " << targetNum << " between " << startRange << " & " << endRange << endl;

    return 0;
}
