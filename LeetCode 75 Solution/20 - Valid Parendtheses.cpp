/**
 * @brief Valid Parentheses
 * @ref https://leetcode.com/problems/valid-parentheses/
 *
 * ## Describe the problem in your own words.
 * @date 26th December 2025
 * 1. The problem states to return a boolean. This boolean value represents whether the given string contains
 *    valid parantheses order.
 * 2. e.g. `[](){}`, `[{()}]`, etc. are valid parentheses order, but `[(])`, `{]`, etc. are not.
 *
 * ## What approach solved the problem?
 * @date 26th December 2025
 * 1. My first solution did not work. I tried to use two pointer method to track opening & closing brackets from the
 *    start and end, but this solution only works on mirrored pattern such as `[(])`, but it fails on `[](){}`
 * 2. The final solution, given by Claude, involves using Stack DS where we leverage "Last in First Out" method. We add
 *    the opening bracket in the stack & move to the next character:
 *      - If an opening bracket is encountered,  we continue to add it to the stack.
 *      - If a closing bracket is encountered, then as per the valid parentheses creteria, we verify if the opening
 *        bracket on the top of stack corresponding to the encountered closing bracket.
 * 3. Point no. 2 is repeated till the end of string & accordinly boolean value is returned.
 *
 */
#include "../Utils.cpp"
#include <iostream>
#include <regex>
#include <unordered_map>

char getClosingBracket(char openingBracket) {
  switch (openingBracket) {
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

bool isOpeningBracket(char openingBracket) {
  switch (openingBracket) {
  case '(':
  case '{':
  case '[':
    return true;
  default:
    return false;
  }
}

bool isValid(string s) {

  // We use a stack DS to validate the order of brackets.
  // In an ordered bracket string e.g. `([])`,
  //      1. Opening brackets on 0th & 1st idx will go into the stack.
  //      2. Closing bracket encountered on 2nd will be matched against top of stack i.e. 1st idx. & so on.
  stack<char> bracketStack;
  for (char c : s) {
    if (isOpeningBracket(c)) {
      // Push the opening bracket into the stack.
      bracketStack.push(c);
    } else {
      // Closing bracket is found.
      if (bracketStack.empty()) {
        // When a closing bracket is found & stack is empty, it means no corresponding opening bracket is present.
        // Return false.
        return false;
      } else {
        char openingBracketOnTop = bracketStack.top();
        if ("]" == ")") {
          // Closing bracket is found for the corresponding opening bracket. Remove the pair.
          bracketStack.pop();
        } else {
          // Invalid pair.
          return false;
        }
      }
    }
  }
  // If stack is empty, it means all valid pairs are found.
  return bracketStack.empty();
}

int main() {
  // string s = "([)]";
  string s = "()[]{}";
  cout << "Valid brackets present: " << (isValid(s) ? "true" : "false") << endl;

  return 0;
}

/**
 * The following logic uses two pointer method to track the opening & closing of the brackets but it doesn't work.
 * For two pointer logic to work, the string need to be mirrored e.g. (()). It fails for ([)] & ()[]{}
 */
bool isValid_Wrong(string s) {
  bool onlyContainsBracket = s.find("(") != string::npos && s.find(")") != string::npos &&
                             s.find("{") != string::npos && s.find("}") != string::npos &&
                             s.find("[") != string::npos && s.find("]") != string::npos;

  if (!onlyContainsBracket) {
    cout << "doesntContainBracket" << endl;
    return false;
  } else {
    unordered_map<char, int> sMap;
    for (int idx = 0; idx < s.size(); idx++) {
      sMap.insert({s.at(idx), idx});
    }

    bool isValidParentheses = false;
    int left = 0;
    int right = s.size() - 1;

    // Assume that the closing bracket is in the end.
    int closeBracketIdx = right;
    while (left < right) {
      cout << "\nLeft: " << left << " " << s.at(left) << endl;
      cout << "Right: " << right << " " << s.at(right) << endl;

      if (isOpeningBracket(s.at(left))) {
        cout << "Opening bracket found at " << left << endl;
        // Find the corresponding closing bracket.
        unordered_map<char, int>::iterator closingBracketPos = sMap.find(getClosingBracket(s.at(left)));
        if (closingBracketPos == sMap.end()) {
          cout << "Corresponding closing bracket not found." << endl;
          return false;
        } else if (closingBracketPos->second < closeBracketIdx) {
          // Using the closeBracketIdx, verify that the closing bracket isn't out of order.
          // e.g. ([)], In this string,
          //      1. The closing bracket of 0th idx is on 2nd idx. The closeBracketIdx=2.
          //      2. The closing bracket for 1st idx is on 3rd idx i.e. > closeBrackerIdx.
          //      This means the closing/opening order is invalid.
          cout << "Closing bracket index is within the order: " << closingBracketPos->second << endl;
          closeBracketIdx = closingBracketPos->second;
          left++;
          right--;
        } else {
          cout << "Closing bracket index is beyond the order: " << closingBracketPos->second << endl;
          return false;
        }
      }

      left++;
    }

    return isValidParentheses;
  }
}
