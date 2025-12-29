/**
 * Reverse Vowels of a String
 * @ref https://leetcode.com/problems/reverse-vowels-of-a-string
 *
 * ## Describe the problem in your own words.
 * @date 16th December 2025
 * 1. The problem states to return a string. This string contains a word with its vowel-sequence in reversed order.
 * 2. e.g. Icecream has [I, e, e, a] vowels at [0, 2, 5, 6] position. The resultant string would be acecreIm. Earlier I
 *    was in 0th pos & now it is in 6th pos. & so forth.
 *
 * ## What approach solved the problem?
 * @date 16th December 2025
 * 1. The solution involves iterating the string & making array for vowelsInString & vowelsPosition.
 * 2. Reverse the vowelPosition array.
 * 3. Now insert vowelChar using vowelPosition while iterating the original string.
 * 4. The above is a niche logic but it ends up reversing the vowels due to step 2.
 */
#include "../Utils.cpp"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string reverseVowels(string s) {
  vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

  // Find out the vowel position & the corresponding char in the string.
  vector<int> vowelPositions;
  vector<char> vowelChar;
  for (int idx = 0; idx < s.size(); idx++) {
    if (find(vowels.begin(), vowels.end(), s.at(idx)) != vowels.end()) {
      vowelPositions.push_back(idx);
      vowelChar.push_back(s.at(idx));
    }
  }

  // Reverse the vowel positions vector.
  vector<int> reverseVowelPositions;
  for (int idx = vowelPositions.size() - 1; idx >= 0; idx--) {
    reverseVowelPositions.push_back(vowelPositions.at(idx));
  }
  cout << "\n======\n";
  cout << vectorIntToString(vowelPositions) << endl;
  cout << vectorCharToString(vowelChar) << endl;
  cout << vectorIntToString(reverseVowelPositions) << endl;

  // Replace the vowels in original string with reversed-vowels.
  for (int idx = 0; idx < reverseVowelPositions.size(); idx++) {
    s.at(reverseVowelPositions.at(idx)) = vowelChar.at(idx);
  }

  return s;
}

string reverseVowelsPtr(string s) {
  string vowels = "aeiouAEIOU";

  // Left & right pointers.
  int left = 0, right = s.size() - 1;

  // Indicates when to swap the left & right characters.
  bool leftSwap, rightSwap;

  while (true) {
    if (left >= right) {
      // Break the loop when left surpasses right.
      break;
    }

    if (vowels.find(s.at(left)) != string::npos) {
      // Vowel found on left pointer.
      leftSwap = true;
    } else {
      // Vowel not found on left, increment the pointer.
      left++;
    }

    if (vowels.find(s.at(right)) != string::npos) {
      // Vowel found on right pointer.
      rightSwap = true;
    } else {
      // Vowel not found on right, decrement the pointer.
      right--;
    }

    if (leftSwap && rightSwap) {
      // Swapping both left & right character.
      swap(s.at(left), s.at(right));

      // Move the pointer after swapping.
      left++;
      right--;

      // Reset the flags.
      leftSwap = false;
      rightSwap = false;
    }
  }

  return s;
}

int main() {
  string s = "IceCreAm";

  cout << "Original string: " << s << endl;
  cout << "Reversed vowel string: " << reverseVowels(s) << endl;
  cout << "Reversed vowel string (using 2 pointer): " << reverseVowelsPtr(s) << endl;

  return 0;
}