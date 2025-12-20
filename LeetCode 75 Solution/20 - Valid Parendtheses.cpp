#include <iostream>
#include "../Utils.cpp"
#include <unordered_map>

char getClosingBracket(char openingBracket)
{
    switch (openingBracket)
    {
    case '(':
        return ')';
    case '{':
        return '}';
    case '[':
        return ']';
    default:
        return openingBracket;
    }
}

bool isOpeningBracket(char openingBracket)
{
    switch (openingBracket)
    {
    case '(':
    case '{':
    case '[':
        return true;
    default:
        return false;
    }
}

bool isValid(string s)
{
    bool doesntContainBracket = s.find("(") == string::npos &&
                                s.find(")") == string::npos &&
                                s.find("{") == string::npos &&
                                s.find("}") == string::npos &&
                                s.find("[") == string::npos &&
                                s.find("]") == string::npos;
    // vector<char> brackets = {'(', ')', '{', '}', '['};
    unordered_map<char, int> sMap;
    for (int idx = 0; idx < s.size(); idx++)
    {
        sMap.insert({s.at(idx), idx});
    }

    if (doesntContainBracket)
    {
        cout << "doesntContainBracket" << endl;
        return false;
    }
    else
    {
        bool isValidParentheses = false;
        int left = 0;
        int right = s.size() - 1;
        int closeBracketIdx = right;
        while (left < right)
        {
            cout << "\nLeft: " << left << " " << s.at(left) << endl;
            cout << "Right: " << right << " " << s.at(right) << endl;

            if (isOpeningBracket(s.at(left)))
            {
                cout << "Opening bracket found at " << left << endl;
                unordered_map<char, int>::iterator closingBracketPos = sMap.find(getClosingBracket(s.at(left)));
                if (closingBracketPos == sMap.end())
                {
                    cout << "Corresponding closing bracket not found." << endl;
                    return false;
                }
                else if (closingBracketPos->second < closeBracketIdx)
                {
                    cout << "Closing bracket index is within the order: " << closingBracketPos->second << endl;
                    closeBracketIdx = closingBracketPos->second;
                    left++;
                    right--;
                }
                else
                {
                    cout << "Closing bracket index is beyond the order: " << closingBracketPos->second << endl;
                    return false;
                }
            }

            left++;
        }

        return isValidParentheses;
    }
}

// && s.at(right) == getClosingBracket(s.at(left))

int main()
{
    // string s = "([)]";
    // string s = "()[]{}";
    // cout << isValid(s) << endl;

    vector<int> v = {51, 132, 349, 204, 426, 388, 462, 105, 324, 0};

    int largestNumber = 0;

    for (int idx = 0; idx < v.size(); idx++)
    {
        if (v.at(idx) > largestNumber)
        {
            largestNumber = v.at(idx);
        }
    }

    cout << largestNumber << endl;

    int secondLargestNumber = 0;

    for (int idx = 0; idx < v.size(); idx++)
    {
        if (v.at(idx) > secondLargestNumber && v.at(idx) < largestNumber)
        {
            secondLargestNumber = v.at(idx);
        }
    }

    cout << secondLargestNumber << endl;

    return 0;
}