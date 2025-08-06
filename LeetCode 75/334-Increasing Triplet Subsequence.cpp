/**
 *  Increasing Triplet Subsequence
 *
 * @ref https://leetcode.com/problems/increasing-triplet-subsequence
 */
#include <iostream>
#include <vector>
#include "../Utils.cpp"

using namespace std;

int main()
{
    // vector<int> nums = {1, 2, 3, 4, 5};
    // vector<int> nums = {20, 100, 10, 12, 5, 13};
    vector<int> nums = {1, 5, 0, 4, 1, 3};
    if(nums.size() < 1 || nums.size() > 500000){
        
    }
    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            if (i < j && nums.at(i) < nums.at(j))
            {
                cout << "Found2 " << i << "\t" << j << endl;
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (j < k && nums.at(j) < nums.at(k))
                    {
                        cout << "Found triplets" << endl;
                        cout << "i:" << i << "\tj: " << j << "\tk: " << k << endl;
                        cout << "nums.at(i): " << nums.at(i) << " \tnums.at(j): " << nums.at(j) << "\tnums.at(k): " << nums.at(k) << endl;
                    }
                }
            }
        }
    }

    return 0;
}
