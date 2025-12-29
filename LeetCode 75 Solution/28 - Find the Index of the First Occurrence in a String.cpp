/**
 * @brief Find the Index of the First Occurrence in a String
 * @ref https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 *
 * ## Describe the problem in your own words.
 * @date 26th December 2025
 * 1. The problem states to return an integer. This integer represents the index of a substring (needle) within a
 *    string(haystack).
 * 2. e.g. The index of 'ippi' in mississippi is 7. The index of 'fat' in 'rambo' is -1.
 *
 * ## What approach solved the problem?
 * @date 26th December 2025
 * 1. My first solution did not work. My idea was to split the main string into a vector of substring. The main string
 *    would be divided based on the 'needle' word's length. e.g. needle="sada", haystack="sadhatsad", so haystack would
 *    be divide into a vector such as [sadh, atsa, d]. This would simplify the searching process. But this failed when
 *    needle="issi", haystack="mississippi". The haystack got divided into [missi, ssip, pi]. No way to find 'issi'.
 * 2. The final solution involved nested loop, where the first loop would iterate each char in main string. On occurance
 *    of 1st char. of needle, we check if the last char. of needle also exists in the haystack, if so, we use an inner
 *    loop starting from the first & last char. of needle to build the entire string & verify accordingly.
 */
#include "../Utils.cpp"
#include <algorithm>
#include <iostream>
#include <vector>

int strStr(string haystack, string needle) {
  int needleSize = needle.size();
  int haystackSize = haystack.size();

  // Constraint Check
  if (needleSize == 0 || haystackSize == 0) {
    return -1;
  }

  // No need to iterate till last word of haystack.
  // Reasoning: e.g. While searching for 'sad'(3 char) in 'happensad'(9
  // char), we only need to iterate till 6th pos. because from 7th pos.
  // there are no 3 chars.
  for (int idx = 0; idx <= haystackSize - needleSize; idx++) {

    // Check the occurance of needle using first & last char & if true
    // build the word in haystack to verify.
    if (haystack.at(idx) == needle.at(0) && haystack.at(idx + needleSize - 1) == needle.at(needleSize - 1)) {
      string needleWord;
      for (int n = 0; n < needleSize; n++) {
        needleWord.push_back(haystack.at(idx + n));
      }

      // Word found, return idx.
      if (needleWord == needle) {
        return idx;
      }
    }
  }

  return -1;
}
int main() {
  // string haystack = "sadbutsad", needle = "but";
  string haystack = "mississippi", needle = "ippi";

  cout << strStr(haystack, needle) << endl;

  return 0;
}

/**
 * This solution did not work on mississippi & issi
 */
int strStr_Wrong(string haystack, string needle) {
  int needleSize = needle.size();
  int haystackSize = haystack.size();
  if (needleSize == 0 || haystackSize == 0) {
    return -1;
  }

  vector<string> haystackVec;
  string haystackWord(1, haystack.at(0));

  for (int idx = 1; idx < haystackSize; idx++) {
    if (idx % needleSize == 0) {
      cout << "Cutting at " << idx << endl;
      haystackVec.push_back(haystackWord);
      haystackWord = "";
    }
    haystackWord.push_back(haystack.at(idx));
  }

  if (!haystackWord.empty()) {
    haystackVec.push_back(haystackWord);
  }

  vector<string>::iterator needlePos = find(haystackVec.begin(), haystackVec.end(), needle);
  if (needlePos == haystackVec.end())
    return -1;
  else
    return (needleSize * (needlePos - haystackVec.begin()));
}
