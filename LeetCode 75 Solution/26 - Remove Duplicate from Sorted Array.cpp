#include <iostream>
#include "../Utils.cpp"
#include <vector>
#include <algorithm>
#include <deque>

int removeDuplicates(vector<int> &nums)
{
    vector<int> vec;
    int previousNum = nums.at(0);

    // deque<int> vecDeque;
    // for (int num : nums)
    // {
    //     vecDeque.push_back(num);
    // }
    int idx = 1;
    while (idx < nums.size())
    {
        if (nums.at(idx) == previousNum)
        {
            nums.at(idx) = nums.at(++idx);
            previousNum = nums.at(idx);
        }
        else
        {
            idx++;
        }
    }

    return idx;
}

int main()
{
    // string s = "([)]";
    // string s = "()[]{}";
    // cout << isValid(s) << endl;

    vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    cout << removeDuplicates(v) << endl;
    cout << vectorIntToString(v) << endl;

    return 0;
}