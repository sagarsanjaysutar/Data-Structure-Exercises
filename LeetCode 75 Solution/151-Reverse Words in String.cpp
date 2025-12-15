/**
 * Reverse words in a String
 *
 * @ref https://leetcode.com/problems/reverse-vowels-of-a-string
 */
#include "../Utils.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s = "the sky is blue";
    // string s = "  hello world  ";
    // string s = "ax good   example";

    // Temporarily saves a single word from the string.
    string sWord = "";

    // List of all the words in the string. Doesn't include whitespace.
    vector<string> sVec;

    // Result string that stores the words in reverse order.
    string result;

    for (int idx = 0; idx < s.length(); idx++) {
        if (!isspace(s.at(idx))) {
            // Built the word, character by character.
            sWord += s.at(idx);
        } else if (isspace(s.at(idx)) && sWord == "") {
            // If whitespace is found & no word is built then skip the iteration.
            continue;
        } else if (isspace(s.at(idx)) && sWord != "") {
            // If whitespace is found & a word is built then add it to the vector & reset the temp variable.
            sVec.push_back(sWord);
            sWord = "";
        }

        if (idx == s.length() - 1 && sWord != "") {
            // Special case to push the last built word into the vector.
            sVec.push_back(sWord);
            sWord = "";
        }
    }

    cout << "Result Vector: " << vectorStringToString(sVec) << endl;

    // Built string is reverse order.
    for (vector<string>::reverse_iterator itr = sVec.rbegin(); itr < sVec.rend(); itr++) {
        result.append(*itr);
        if (itr + 1 != sVec.rend())
            result.push_back(' ');
    }

    cout << "Result string: " << result << endl;

    return 0;
}